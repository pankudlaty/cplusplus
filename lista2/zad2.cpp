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
        void pokaz_dane(){
            cout << endl;
            cout << 
            "Imie:" << getImie() << endl << 
            "Nazwisko:" << getNazwisko() << endl << 
            "Wiek:" << getWiek() << endl;
            cout << endl;
};
        Osoba(string imie, string nazwisko, int wiek){
            setImie(imie);
            setNazwisko(nazwisko);
            setWiek(wiek);
        };
        Osoba(){};
};
class Student : public Osoba {
    friend void wprowadz_dane(Student &stu){
        string imie, nazwisko, grupa;
        int wiek;
        cout << "Wprowadz imie, nazwisko, wiek oraz grupe: ";
        cin >> imie;
        stu.setImie(imie);
        cin >> nazwisko;
        stu.setNazwisko(nazwisko);
        cin >> wiek;
        stu.setWiek(wiek);
        cin >> grupa;
        stu.grupa = grupa;
    }
    private:
        string grupa;
    public:
        void pokaz_dane(){
            cout << endl;
            cout << 
            "Imie:" << getImie() << endl << 
            "Nazwisko:" << getNazwisko() << endl << 
            "Wiek:" << getWiek() << endl << 
            "Grupa:" << grupa<< endl;
            cout << endl;
        };
        Student(string imie, string nazwisko, int wiek, string grupa){
            setImie(imie);
            setNazwisko(nazwisko);
            setWiek(wiek);
            this->grupa = grupa;
        };
        Student(){};
};
class Pracownik : public Osoba
{
friend void wprowadz_dane(Pracownik &prac){
    string imie, nazwisko, stanowisko;
    int wiek;
    cout << "Wprowadz imie, nazwisko, wiek oraz stanowisko: ";
    cin >> imie;
    prac.setImie(imie);
    cin >> nazwisko;
    prac.setNazwisko(nazwisko);
    cin >> wiek;
    prac.setWiek(wiek);
    cin >> stanowisko;
    prac.stanowisko = stanowisko;
}
private:
    string stanowisko;
public:
    void pokaz_dane() {
         cout << endl;
         cout << 
         "Imie:" << getImie() << endl << 
         "Nazwisko:" << getNazwisko() << endl << 
         "Wiek:" << getWiek() << endl << 
         "Stanowisko:" << stanowisko << endl;
         cout << endl;
    };
    Pracownik(string imie, string nazwisko, int wiek, string stanowisko) {
        setImie(imie);
        setNazwisko(nazwisko);
        setWiek(wiek);
        this->stanowisko = stanowisko;
    };
    Pracownik(){};
};
int main() {
   
    Student studentTest;
    wprowadz_dane(studentTest);
    Pracownik pracownikTest;
    wprowadz_dane(pracownikTest);
    studentTest.pokaz_dane();
    pracownikTest.pokaz_dane();
}