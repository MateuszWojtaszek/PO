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

