# Programowanie Obiektowe
## 1.Podstawowe pojęcia związane z programowaniem obiektowym
### Obiekt i klasa

-Klasa jest swego rodzaju przepisem na stworzenie danego obiektu.
Każdy obiekt posiada swoje cechy oraz operacje na podstawie przepisu.

### Abstrakcja

- TO COS INNEGO NIŻ KLASA ABSTRAKCYJNA!

- To zredukowanie analizowanego problemu, modelu do tylko i wyłącznie cech
istotnych z punktu widzenia problemu który chcemy rozwiązać.


### Hermetyzacja

-stan(dane) obiektu dostępne są tylko za pośrednictwem interfejcu klasy.

-polega to w skrócie na ukrycie danych lub metod obiektu aby były dostępne tylko i wyłącznie dla innych funkcji tej klasy.

-stosujemy ją aby zabezpieczyć stan obiektu przed niekontrolowanymi zmianami.

-jeśli stan obiektu jest ściśle ukryty i dostępny tylko według ściśle zdefiniowanych funckji nazywamy pełną hermetyzacją
### Interfejs Klasy

-są to funkcje dostępne dla świata zewnętrznego(czyli funkcje w polu public)

#### Przykład

---
````c++
class foo{
int dana1=2;
protected:
int dana2=1;
public:
//interfejs klasy:
int cos();
float cos2();
foo();
int dana3=3;
};

int main(){
foo test;
test.dana3=5; // gites bo jest public
test.dana2=4; // nie git, kompilator daje błąd bo jest protected. Protected nie należy do interfejsu klasy
test.cos(); // gites;
}
````
---
### Tworzenie Klasy - plik .cpp oraz .h 
include sluży tylko do .h !!! NIgdy nie uzywamy go do cpp
- Plik.h
````c++
class puszka{
//jakies dane
float temperature;
const int can_volume;
const std::string beer_type; // zmienna const która musi miec
                            // nadaną wartość w momencie deklaracji 
                            // oraz nie mozna go poźniej nadpisać

public:
    puszka(); //konstruktor - nie tworzy obiektu, tylko go inicjuje!!!
    puszka(const std::string &type, int volume)
    void info() const; // funkcja która nie zmienia 
                      // stanu żadnej zmiennej
};
// jeśli mamy konstruktor, który można wywołać z jednym parametrem
// to należy przed nim dopisać explicit
// konstruktor który można wywołać z jednym parametrem odrazu 
// pozwala na przekonwertowanie dowolnego typu 
// na typ klasy(dziala jako operator konwersji) 
// (moze to prowadzic do błędów lub kontrowersji)
// dodanie explicit wyłącza niejawną konwersje co zapobiega błędą
explicit puszka(const std::string &type, int volume=500)

````
- Plik.cpp
````c++
//Definicje funkcji (w tym konstruktora bądź konstruktorów)
puszka::puszka() {
//cos np:
temperature = 18;
}
//została tutaj użyta lista inicjalizacyjna, służy ona do inicjalizacji wartości
// dla zmiennych typu const oraz innych zmiennych
//z listy trzeba!!! korzystac gdy:
//-mamy pola const
//-mamy pola które są referencjami np 
// std::vector<int>& vec ,który jest referencją na vector typu int
puszka::puszka(const std::string &type, int volume)
:beer_type(type),can_volume(volume){
    
}

//konstruktor delegujący - wykonuje się po zwykłym konstruktorze
puszka::puszka("Bączek", 500);



````
## Dodatkowe uwagi do konstruktorów

- jeśli nie stworzymy ręcznie własnego wygeneruje się domyślny konstruktor który nic nie robi.

- nie ma problemu z tworzeniem tablicy obkietów danej klasy przy użyciu domyślnego konstruktora

- NATOMIAST JEŚLI NIE ISTNIEJE DOOMYŚLNY KONSTRUKTOR LUB BEZARGUMNTOWY to stworzenie tablicy spowoduję błąd!.
- mamy 2 opcje : zainicjować każdy obiekt - podac ich argumenty przy inicjacji; stworzyc konstruktor bezargumentowy; rezygnowac z tablic i robic wektor ktory bedzie rozszerzany przy tworzeniu obiektu

## DESTRUKTORY

- nie niszczy obiektu tylko jest automatycznie wywolanu tuż przed jego zniszczeniem
- jego zadaniem jest posprzątanie po projekcie (rzadko się je pisze np. przy tablicach dynamicznych)
- Tworzenie: ~Nazwa(); Nazwa::~Nazwa()
- Moze być tylko 1
- nie ma typu
- nie mozna go wywołać z parametrami 
- Destruktory wywołują się od końca 

## Składowe statyczne wewnątrz klasy

- jest to wspólne dla wszystkich obiektów tego typu (w pamięci alokowane tylko raz)
- przyklad stosowania: ilość stworzonych obiektów
- typ static  musi zostac zdefiniowany, robimy to tak:
````c++
<góra pliku.cpp>
int foo::counter; // deklaracja
.
.
.
<plik.h>
class foo{
    static int counter; //inicjacja
};
````
- zmienne statyczne są tak naprawde globalne ale dostosowane do danej klasy
- można się do niej odwołać bez tworzenia obiektu wykorzystując nazwe klasy: Nazwa::counter
- to u góry dziala tylko jak zmienna jest publiczna
- jeśli jest ona prywatna mozemy stworzyc publiczna funkcje satyczną która będzie zwracać nam zmienną.

### Funkcja statyczna a zwykła

- zwykła funkcja w klasnie zawiera niewidoczny wskaźnik *this, który informuje ją dla jakiego obiektu danej klasy ma być wywołana dana funkcja
- funkcja statyczna tego wskaźnika nie posiada, dlatego może się odwoływać jedynie do zmiennych statycznych

# 2.Obiektowe Projektowanie aplikacji

## Metoda kart CRC

- Class-Responsibilities-Collaborators (klasy-obowiązki-współpracownicy)
- Polega na stworzeniu tabelki podczas rozważania problemu:

  |                                	| Class 	|                                                                   	|
  |--------------------------------	|:-----:	|------------------------------------------------------------------:	|
  | Responsibilities               	|       	|                                                     collaborators 	|
  | -co musi wiedzieć              	|       	|                                          z kim klasa współpracuje 	|
  | jakie operacje musi umożliwiać 	|       	| lepiej wpisać z jakimi obiektami innych klas musimy współpracować 	|

## Derektywy ifndef,define
- derektywy, które służą do zabezpieczenia, przed wielokrotnym dołączeniem tego samego pliku nagłówkowego
- Przykład:
````c++
#ifndef CPP_2023_W_03_BOARD_H
#define CPP_2023_W_03_BOARD_H
````

## Referencje
- jeśli chcemy przekazać orginalny obiekt do naszej klasy to musimy mieć 2 rzeczy:
````c++
//pierwsza to zmienna która przechowa referencje,bo gdyby jej nie bylo to wartość zostałaby skopiowana
Board & board;
public:
    //posiadać konstruktor, który jako argument przyjmnie referencje na obiekt
    Player(const std::string &n, Board &b);
    // w przypadku const referencji deklarujemy, że nie zmienimy orginału
````
## Kolejność inicjalizacji w licie inicjalizacyjnej
- koljeność jest taka sama jak przy deklaracji zmiennych w klasie.
- Czyli przykładowo powinno to wyglądać następująco
```c++
//mamy kalse
class foo(){
    //mamy zmienne
    const std::string &name;
    Board & board;
public:
    //Mamy konstruktor z listą inicjalizacyjną
    foo(const std::string &n,Board &b): name(n),board(b);
    
} 

```

## Przykład testowania Funkcji

- stworzenie pliku z assertami które testują nasz kod i przy urzyciu cmake sprawdzać poprawność testów przy każdej kompilacji

# Przeciążanie Operatorów.

- W c++ można zdefiniować nowe znaczenie dla operatorów. Istnieją jednak ograniczenia:
- tylko istniejące operatory, nie można zmieniać ich właściwości czyli priorytetu, łączności i liczbę argumentów.
- nie każdy operator można przeciążyć np.:
- . (dostęp do składowej klasy/struktury)
- ::
- sizeof
- ?:
- .*
- Wiekszość operatorów można przeciążać na 2 sposoby:
- zwykła funkcja
- funkcja składowa (wywoływana dla konkretnego obiektu)

Jak przeciążyć operatory?
```c++
//jako funkcja  globalna
// c3 * 10
// trzeba ją w klasie zrobić friend
Complex operator*(const Complex &larg, double rarg ){
    Complex rv = larg;
    rv.re = larg.re * rarg;
    rv.im = larg.im * rarg;
    return rv;
}
.
.
.
//wewnątrz klasy

friend Complex operator*(const Complex &larg, double rarg );
.
.
.
//jako funkcja składowa
// c2.operator+(c3)
Complex operator+ (const Complex &arg) const;
// pierwszy const mówi że nie zmieniamy prawego argumentu a drugi że lewego
// zwracamy obiekt typu Complex
.
.
.
//przykładowa definicja
Complex Complex:: operator+ (const Complex &arg) const{
    Complex tmp_c;
    tmp_c.re=this->re + arg.re;
    tmp_c.im = im + arg.im;
    return tmp_c;
}
```
## Przykład z std::cout

```c++
// jeśli chcielibyśmy przciążyć ten operator jako funkcje składową,
// czego nie powinno się robić, musielibyśmy ingerować w klase std::cout
// czyli wybieramy opcje globalną, w ostream nie dajemy const bo modyfikujemy strumien
// zwracamy obiekt przez referencje ponieważ chcemy zwrócić konkrety dany strumień który użyliśmy
// czyli do referencji w zwracaniu używamy gdy chcemu zwrócić już istniejący obiekt
std::ostream &operator<<(std::ostream &str,const Complex &c){
    str<<c.re<<"+"<<c.im<<"i";
}

```

## Operator konwersji

- w przypadku operatorów konwersji mamy 2 możliwości:
- Jakis typ T --> Complex // konstruktor bez explicit

bądź jeśli mamy konstruktor z explicit to możemy to przekonwertować w sposób jawny
```c++
c1=10; //zadziala tylko bez explicit
c1=static_cast<Complex>(10) // zadziała z explicit
```
- Complex --> T
```c++
double operator double()const{
    //cos np modół liczby zespolonej xd
} 
```
- Uwaga! przy kilku operatorów konwersji kompilator może mieć problem ze stwierdzeniem jakiego operatora użyć.
- Trzeba wtedy ustawiać konwersje ręcznie

# Dziedziczenie
- Jeśli chcemy wykorzystać częściową impementacje z innej klasy to możemy zrobić, że nasza nowa klasa bazuje na istniejącej klasie 
```c++
class Osoba{
    std::string imie;
public:
    explicit Osoba(const std::string &im)
    void info() const;
};

Osoba::Osoba(const std::string &im): imie{im}{}

.
.
.
//     typ dziedziczenia
class Student: public Osoba{
    int indeks;
    // nie powtarzamy zmiennych
public:
    // klasie pochodnej mozemy nadpisac odziedziczoną funkcje z klasy bazowej 
    void info() const; // -> nadpisana funkcja musi miec tą samą sygnature
    
};
.
.
.
// konstruktor klasy która dziedziczy najpierw wywołuje konstruktor klasy bazowej
Student::Student(const std::string &im ,int id):Osoba(im), indeks(id){
    
}
```
- Czego nie dziedziczymy?
- Konstruktorów, destruktory, operator przypisania 
- To że cos jest dziedziczone nie oznacza ze odrazu mamy do tego dostęp!
- Typy dziedziczenia
- public -> public na public, protected na protected, privet na privet 
- protected -> public na protected, protected na protected, privet na privet
- privet -> wszystko na privet
- Czyli w skrócie dziedziczenie nie daje nam dostepu do zmiennych privet, jedynie do public i protected
- Protected:
- mają do niej dostęp tylko metody klasy oraz pochdne z tej klasy
```c++
//przydanty sposób wykorzystywania funkcji z kalsy bazowej w klasie pochodnej
Osoba::info(); //-> metoda z klasy bazowej
info(); //-> metoda z klasy pochodnej
```
## Kiedy używać dziedziczenia?

- podczas projektowania, miedzy rzeczami występują relacje:
- silnik i samochód -> sammochód "Posiada" silnik(<b>has a</b>)
- Osoba i Student -> szczególny typ osoby (<b>is a</b>)
- Samochód i Parking -> Parking "posiada samochód"(<b>has a</b>)
- Prostokąt i kwadrad -> szczególny typ prostokąta (<b>is a</b>)
- Jeśli zachodzi relacja <b>HAS A</b> dziedziczenie jest wykluczone !
- Jeśli zachodzi relacja <b>IS A</b> można pomyśleć nad dziedziczeniem

## UML - Język modelowania
- wykorzystywany do projektowania programów
<img src="_001">
- extend -> dziedziczenie
- asosjacja -> korzystanie np.: wartość referencja
- Agregacja -> pole które będzie właścicielem danego obiektu
- kompozycja -> to samo co agregacja ale czas "zycia" obiektów jest współdzielony

## Relacja Baza - Pochadna
```c++
Ososba o{"Jan"};
Student s{"Anna",123456};
//która opcja jest legalna?
o=s; // legalne
s=o // ERROR
```
- Czemu? Ponieważ podczas wywoływania opcji 1 kompilator obetnie sobię wszystko co nie należy do osoby 
i przypisze osobie wartości osoby z pochodnej student.
- W opcji drugiej, kompilator nie dostaje wszystkich danych od osobydo przypisania wartości dla studenta
np. jego nr. indeksu
- w skrócie, każdy student jest osobą czyli możemy ze studenta zrobić osobę,
a nie z każdej osoby można zrobic studenta 
## Przykład zastosowania tej relacji
```c++
void foo(Osoba o){
    o.info;
}
.
.
.
foo(o);
foo(s);
// wywołamy metodę z klasy bazowej dla osoby i studenta
// Uwaga - nie użyjemy nadpisanej funkcji przez klase studnet
```
## Wskaźnik i klse Bazowna - Sztos opcja
```c++
//jeśli stworzymy wskaźnik na klase bazowną i przekarzemy sobie do niego adres klasy pochodnej 
// to dzieją się interesujące rzeczy

void foo(Osoba *o){
    o->info();
}
.
.
.
foo(&osoba);

foo(&studnet);
```
- co dostaniemy? W tym wypadku wywoła się metoda info dla klasy bazowej (jeśli założymy że klasa została napisana tak jak wyżej)
- To dlaczego jest to sztos opcja? Odpowiedz ukrywa się w słowie wirtual:
```c++
//zmodyfikujmy klase bazową i klase pochodną 

class Osoba{
std::string imie;
public:
explicit Osoba(const std::string &im)
virtual void info() const; // dodajemy słowo virtual, które mówi kompilatorowi
                          // że ma zwrócić uwagę na tą funkcje przy innych operacjach - tak w skrócie
                          // dokładniej -> zmieniamy opcje patrzenia na wskaźnik kompilatora jako wywołanie metody
                          // nie z typu wskaźnika a z typu obiektu na jaki wskazuje
};

class Student: public Osoba{
int indeks;

public:

void info() const override; // utwierdzamy kompilator, że chcemy nadpisać funkcje virualną

};
```
- Co otrzymamy po ponownym wywołaniu foo()?
```c++
void foo(Osoba *o){
    o->info(); // teraz wywoła się metoda dla obiektu który jest wskazywany przez wskaźnik
}
.
.
.
foo(&osoba); // czyli tutaj wywoła się info z klasy osoba bo wskazuje na osobe

foo(&studnet) // a tutaj wywoła sie info z klasy pochodnej student, bo wskazuje na studenta;
- ```
- override zabezpiecza nas też przed pomyłkami(np. literówki w funkcji którą chcemu nadpisać)