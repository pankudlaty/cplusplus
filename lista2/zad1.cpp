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
Osoba::Osoba(){}
class Student : public Osoba {
    private:
        string grupa;
    public:
        void pokaz_dane();
        //Student(string imie, string nazwisko, int wiek, string grupa);
        Student(){
            string imie, nazwisko;
            int wiek;
            cout << "Podaj imie: ";
            cin >> imie;
            setImie(imie);
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            setNazwisko(nazwisko);
            cout << "Podaj wiek: ";
            cin >> wiek;
            setWiek(wiek);
            cout << "Podaj grupe: ";
            cin >> this->grupa;
        };
        
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
class Pracownik : public Osoba
{
private:
    string stanowisko;
public:
    void pokaz_dane();
    //Pracownik(string imie, string nazwisko, int wiek, string stanowisko);   
    Pracownik(){
            string imie, nazwisko;
            int wiek;
            cout << "Podaj imie: ";
            cin >> imie;
            setImie(imie);
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            setNazwisko(nazwisko);
            cout << "Podaj wiek: ";
            cin >> wiek;
            setWiek(wiek);
            cout << "Podaj stanowisko: ";
            cin >> this->stanowisko;
    };
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
int main() {
   
    Student studentTest;
    Pracownik pracownikTest;
    studentTest.pokaz_dane();
    pracownikTest.pokaz_dane();
}



