# Podstawy
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
