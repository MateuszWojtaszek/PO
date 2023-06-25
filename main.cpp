#include <iostream>

class Interface{
    // nie ma żadnych danych !

    // nie ma definicji funkcji, tylko deklaracej

    virtual void initialize_device() = 0; // funkcja czysto wirtualna
    // ten zapis oznacza, że funkcja nie posiada definicji w klasie w której się znajduje

    // jeśli klasa zawiera choćby jedną funkcje czysto wirtualną
    // to staję się klasą abstrakcyjną
};




int main(){

}