#include "stdlib.h"
#include <string>
#include <iostream>

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
        void setImie(string imie) {
            this->imie = imie;
        }
        string getNazwisko(){
            return nazwisko;
        }
        void setNazwisko(string nazwisko) {
            this->nazwisko = nazwisko;
        }
        int getWiek() {
            return wiek;
        }
        void setWiek(int wiek) {
            this->wiek = wiek;
        }
    public:
        void pokaz_dane();
        Osoba(string imie, string nazwisko, int wiek);
        Osoba();
};
void Osoba::pokaz_dane() {
    cout << endl;
    cout << 
    "Imie:" << getImie() << " " << 
    "Nazwisko:" << getNazwisko() << " " << 
    "Wiek:" << getWiek() << endl;
    cout << endl;

}
Osoba::Osoba(string imie, string nazwisko, int wiek) { 
    setImie(imie);
    setNazwisko(nazwisko);
    setWiek(wiek);
}
Osoba::Osoba(){}
class Student : public Osoba {
    private:
        string grupa;
    public:
        void pokaz_dane();
        Student(string imie, string nazwisko, int wiek, string grupa);
        
};
void Student::pokaz_dane() {
    cout << endl;
    cout << 
    "Imie:" << getImie() << " " << 
    "Nazwisko:" << getNazwisko() << " " << 
    "Wiek:" << getWiek() << " " << 
    "Grupa:" << grupa<< endl;
    cout << endl;
}
Student::Student(string imie,string nazwisko, int wiek, string grupa) {
    setImie(imie);
    setNazwisko(nazwisko);
    setWiek(wiek);
    this->grupa = grupa;
}
class Pracownik : public Osoba
{
private:
    string stanowisko;
public:
    void pokaz_dane();
    Pracownik(string imie, string nazwisko, int wiek, string stanowisko);   
};

void Pracownik::pokaz_dane() {
    cout << endl;
    cout << 
    "Imie:" << getImie() << " " << 
    "Nazwisko:" << getNazwisko() << " " << 
    "Wiek:" << getWiek() << " " << 
    "Stanowisko:" << stanowisko << endl;
    cout << endl;
}

 Pracownik::Pracownik(string imie, string nazwisko, int wiek, string stanowisko) {
    setImie(imie);
    setNazwisko(nazwisko);
    setWiek(wiek);
    this->stanowisko = stanowisko;
}

int main() {
   
    Osoba osobaTest("Pawel", "Kownacki", 32);
    Student studentTest("Rangar","Hafdansson",22, "Programowanie");
    Pracownik pracownikTest("Jan", "Nowak", 34, "IT Administrator");
    studentTest.pokaz_dane();
    osobaTest.pokaz_dane();
    pracownikTest.pokaz_dane();
}



