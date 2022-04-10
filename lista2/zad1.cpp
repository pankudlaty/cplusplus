#include "stdlib.h"
#include "stdio.h"
#include <string>

using namespace std;

class Osoba {
    private:
        string imie;
        string nazwisko;
        int wiek;
    protected:
        string getImie(){
            return imie;
        }
    public:
        void pokaz_dane();
        Osoba(string imie, string nazwisko, int wiek);
};

void Osoba::pokaz_dane() {
    printf("\n");
    printf("Imie: %s Nazwisko: %s Wiek: %d",imie, nazwisko, wiek);
    printf("\n");
}

Osoba::Osoba(string imie, string nazwisko, int wiek) { 
    imie = imie;
    nazwisko = nazwisko;
    wiek = wiek;
}

class Student : public Osoba {
    private:
        string grupa;
    public:
        void pokaz_dane();
        Student(string imie, string nazwisko, int wiek, string grupa);
        
};
void Student::pokaz_dane() {
            printf("\n");
            printf("Imie: %s Nazwisko: %s Wiek: %d Grupa: %s",imie, nazwisko, wiek, grupa);
            printf("\n");
}

Student::Student(string imie, string nazwisko, int wiek, string grupa) {
    imie = imie;
    nazwisko = nazwisko;
    wiek = wiek;
    grupa = grupa;
}

class Pracownik : public Osoba
{
private:
    string stanowisko;
public:
    void pokaz_dane();
    Pracownik(string imie, string nazwisko, int wiek, string stanowisko);   
};


 Pracownik::Pracownik(string imie, string nazwisko, int wiek, string stanowisko) {
    imie = imie;
    nazwisko = nazwisko;
    wiek = wiek;
    stanowisko = stanowisko;
}

int main() {
   
    Osoba osobaTest("Paweł", "Kownacki", 32);
    Student studentTest("Paweł", "Kownacki", 32, "Programowanie");
    Pracownik pracownikTest("Paweł", "Kownacki", 32, "IT Administrator");

    osobaTest.pokaz_dane();
    studentTest.pokaz_dane();
    pracownikTest.pokaz_dane();

}



