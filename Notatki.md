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
### ciekawostka z wykładu - mutable
```c++
// jeśli mamy w klasie zmienną którą z jakiegoś dziwnego powodu chcemy zmodyfikować w funkcji const
// to możemu przy delkaracji zmiennej dodać słowo mutalble
mutable int cooldown ;
```

## "Koszty" Funkcji Virtualnych

 Koszty stałe:
- Zostanie utworzona tablica która będzie zawierać adresy każdej funkcji virtualnej w klasie - koszt pomijalnie mały.
- jeśli mamy klase w której znajduje się conajmniej jedną klase virtualną to obiek tego typu zostanie automatycznie powiększony o jeden doatkowy wskaźnik - zwiększa się znacząco rozmiar naszego obiektu -> też rzadko się tym przyjmujemy
- ten wskaźnik wskazuje na tablice z adresami funkcji virtualnych
- Koszt 3 wiąże się z wywołaniem funkcji wirtualnej. Wykonujemy jeden dodatkowy odczyt z pamięci

# Dziedziczenie wielu klas

- W c++ możemy dziedziczyć  wiele klas na raz. Dostajemy wtedy wszystko z obydwu klas. Problem poajawia się jeśli klasy te ma ją te same zmienne bądź funkcje o tych samych nazwach.
- Należy wtedy wybrać do jakiej zmiennej chcemy się odwołać
```c++
// pierwsza prymitywna klasa
  class A{
  protected:
  int val;
  public:
  A();
  };

A::A() {
val=1;
}
// druga prymitywna klasa
class B{
protected:
int val;
public:
B();
};

B::B() {
val=2;

}
// klasa dziedziczaca 2 klasy, (konstruktory wywołują się w kolejności podanego dziedziczenia)
// czyli najpierw konstruktor A potem B na końcu C
class C:public A,public B{
public:
C();
[[nodiscard]] int get_val() const;
};

C::C() = default;

int C::get_val() const {
return A::val; // definiujemy jaką zmienną z dziedziczonych klas zwraca funkcja
}
```
# PROBLEM DIAMENTU

Wyobraźmy sobie że mamy klase bazową A, następnie dwie klasy pochodne od A -> B1 oraz B2. Po tym wszystkim tworzymy klase C która jednoczśnie dziedziczy klase B1 oraz klase B2.
Jaki mamy problem? A minaowicie taki, że wszystko zmienne klasy bazowej A się dupliukją w klase C i musimy z tą duplikacją walczyć.
- 1 sposobem jest ręcznę wybieranie z której "ścieżki" dziedziczenia korzystamy

przykładowo:
```c++
class A{
protected:
    int val;
public:
    A();
};

A::A() {
val=0;
}

class B1:public A{
};

class B2:public A{
public:
    B2();
};

class C:public B1,public B2{
public:
    int get_val();
};

int C::get_val() {
    return B1::val; // ręcznie wskazujemy "ścieżkę" dziedziczenia
}
```
- 2 sposobem jest określenie we weczśniejszych klasach dziedziczenia virtulanego, które powoduję, że pole które się duplikuję się uwspólnia

przykład:
```c++
class A{
protected:
    int val;
public:
    A();
};

A::A() {
val=0;
}

class B1:public virtual A{ // dziedziczenie virtualne
};

class B2:public virtual A{ // dziedziczenie virtualne
public:
    B2();
};

class C:public B1,public B2{
public:
    int get_val();
};

int C::get_val() {
    return val; // brak probelmu z wartością 
}
```
- Pojawia się niestety mały problem jeśli posiadamy konstruktor kalsy A który przyjmuje jakieś argumenty. Występuje wtedy bląd podczas tworzenia obiektu C. Powiedzmy, że stworzyliśmy konstryktory dla klas B1 i B2 które inicjalizują Konstruktor klasy bazowej A. To przy tworzeniu obiketu C pojawia się problem, kompilator nie wie, jaką wartość ma uwspólnić. Dlatego musimy zdefiniować konstruktor klasy C i zdefiniować wywołanie konstruktora dla Klasy A, wtedy wartość zostaję uwspólniona i konstruktor A nie wywołuję się już dla klas B1 oraz B2.

przykład:
```c++
class A{
protected:
    int val;
public:
    A(int v);
};

A::A(int v):val(v) {
}

class B1:public virtual A{
public:
    B1();
};

B1::B1():A{1} { wywołanie A{1} sie nie wykona dla tworzenia obietu klasy C

}

class B2:public virtual A{
public:
    B2();
};

B2::B2():A{2} { // wywołanie A{2} sie nie wykona dla tworzenia obietu klasy C

}

class C:public B1,public B2{
public:
    int get_val();
    C();
};

int C::get_val() {
    return val;
}

C::C(): A(10) { // nie bedzie blędu, wartość val zostaje uwspolniona w tym miejscu

}
```
### Kiedy Dziedziczenie wieloklasowe nie powoduje konfliktów?
Kiedy klasy z których dziedziczymy spełniają specyficzne warunki:
- nie posiadają żadnych danych oraz pól
- nie posiadają żadnych zdefiniowanych funckji 
- Te klasy nazywają się w innych jezykach nazywa się interfejsem

przykład:
```c++
// nie można stworzyć obiektu klasy abstrakcyjnej!!!
class Interface{
    // nie ma żadnych danych !

    // nie ma definicji funkcji, tylko deklaracej

    virtual void initialize_device() = 0; // funkcja czysto wirtualna
    // ten zapis oznacza, że funkcja nie posiada definicji w klasie w której się znajduje

    // jeśli klasa zawiera choćby jedną funkcje czysto wirtualną
    // to staję się klasą abstrakcyjną
};
```

# STL
## Podstawowe komponety STL
- kontenery
- iteratory
- algorytmy
## Kontenery
1. Kontenery sekwencyjne - jakies elementy znajdują się od innych w określonej odległości
2. Kontenery niesekwencyjne
3. Adaptery kontenerów - wykorzystują istniejące kontenery i modyfikują je do określonych celów
### Kontenery sekwencyjne
1. std::vector
2. std::deque
3. std::list
#### std::vector
- Elementy są umieszczone w pamięci dokladnie tak samo jak w tablicy (ciągle obok siebie)          
- Dostęp do elementu ```vec[i]``` jest operacją o złożoności O(1)
- Modyfikacja wekotra (wstawiania/kasowanie elemetów) - O(n)
- Wyjątek dla ostatniego elementu ma złożoność =O(1)
#### std::deque
- Elementy nie są umieszczone w sposób ciągły          
- Dostęp do elementu ```vec[i]``` jest operacją o złożoności O(1)                 
- Modyfikacja wekotra (wstawiania/kasowanie elemetów) - O(n)              
- Wyjątek dla ostatniego lub pierwszego elementu ma złożoność =O(1)
#### std::list
- Elementy są umieszczone losowo w pamięci 
- Dostęp do elementu ```lst[i]``` jest operacją o złożoności O(n)
- łatwo dodać lub usunąć element w każdym miejscu - O(1) (ale...jeśli mamy wskaźnik/iterator na konkretne miejsce w liście!)
#### std::set
- Dany element może występować tylko raz
- służy do sprawdzenia czy coś występuje w zbiorze;
#### std::map
- Reprezentuje tablice gdzie kluczem jest dowolny typ
- odpowiednik dictionary z pythona

### ITERATOR
- potrafią poruszać się po kolekcji
- pozwalają nam dobrać się do zawartości kolekcji na który wskazują
- mozna je przypisac,inkrementować
Kategorie iteratorów:
- iteratory wejściowe -> można wykonać dereferencje w kontekcie r-value. przykład: cout<<*a.
- iteratory wyjściowe -> dereferencja w kontekscie l-value. przykład: *a=9;
- forward -> wejsciowe + wyjsciowe + posiadają domyślny konstruktor oraz posiadają tzw. "multipass"
- Biderectional(dwukierunkowy) -> forward+możliwość dekrementacji
- Random Access Iterator -> wszystko poprzednie + mozna do iteratora a: a+n,a-n, a<n, a>n, a[n]
- 
##### Złożoność
- O(1) - czas działania nie zależy od rozmiaru problemu
- O(n) - czas działania jest liniowo zależny od rozmiaru problemu
- O(n^2)
- O(n^3) ...
- O(ln n)
- O(n*ln n)
- O(2^n)
### Algorytmy w STL
Aby korzystać trzeba załączyć derektywy
```c++
#include <algorithm>
#include <numeric>
```
Algorytmy nie modyfikujące kontenera:

std::all_of() -> czy wszystkie elementy kolekcji spełniają warunek
```c++
//bool all_of(Input first, Input last, UnaryPredicate p)
// iterator na pierwszy element, na ostatni, i ???
//Predicate - "pytanie" na które można odp. tak lub nie
// UnrayPredycate - predykat operujący na 1 wartości
//przykład zastosowania:
std::list v ={2,3,4,5,3};
bool Czy_podzielne_przez_2(int value){
    if(value%2==0) return true;
    return false;
}
all_of(begin(v),end(v),Czy_podzielne_przez_2);
```
W miejcu funkcji można również wstawić obiekt klasy ze zdefiniowanym operatorem(). Inaczej nazywany obiektem funkcyjnym
#### LAMBDA EXPRESSION - funkcja anonimowa
```c++
[x] (int value)->bool {return value<x}
// []- takjaby start definicji, i można tu przekazać dla funkcji dla &-wszystko przez referencje, = -> wszystko przez wartość
// (przyjmowane parametry)->wynik operacji 
// {kod który wykonuje przekształcenie (operacje) }
```

std::any_of() -> czy w kolekcji cokolwiek spełnia warunek

std::none_of() -> czy żaden element kolekcji nie spełnia warunku

reszta z tej podgrupy działa podobnie.

std::count() -> sprawdza ile razy cos występuje w kolekjci

std::count_if() -> sprawdza ile jest czegos pod jakims warunkiem

std::find() -> na jakiej pozycji jest pierwszy podany element

std::find_if() -> na jakiej pozycji jest pierwszy element spełniający warunek to zwraca iterator!!

------
Algorytmy  modyfikujące kontener:

std::sort() -> sortuje 
```c++
std::sort(begin(v), end(v));
std::sort(begin(v), end(v), std::greater<int>()) //-> sortuje odwrotnie : od najwiekszego 
```
Fajna sztuczka dla wlasnego typu danych
```c++
struct Student{
    int indeks;
    string imię;
};

std::vector<Student> v{{"Adam",123456},{"Wojtek",432132}};
std::sort(begin(v),end(v),
          [](const Student &s1, const Studnet &s2){return s1.index<s2.index})
```



