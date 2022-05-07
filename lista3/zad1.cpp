#include "stdlib.h"
#include <iostream>
#include <string.h>
#include <time.h>

const int N = 5;

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
    private:
        string grupa;
    protected:
        string getGrupa(){
            return grupa;
        }
        void setGrupa(string grupa) {
            this->grupa = grupa;
        }
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
class Pracownik : public Osoba {
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
class StudentEdukacja: public Student 
{
    friend class studentSort;
private:
    int numer_indeksu;
public:
   // void podaj_numer_indeksu() {
   // };
    StudentEdukacja(string imie, string nazwisko, int wiek, string grupa, int numer_indesku){
        setImie(imie);
        setNazwisko(nazwisko);
        setWiek(wiek);
        setGrupa(grupa);
        this->numer_indeksu = numer_indeksu;
    };
    StudentEdukacja(){};
    
};
class studentSort {
    private:
        StudentEdukacja students[N];
        void sortArray(){

        };
    public:
        void fillArray(){
            srand(time(NULL));
            for (int i=0; i<N; i++) { 
                students[i] = StudentEdukacja("Jan", "Kowalski", rand()%99, "Programowanie", rand());
            }
        };
        void showArray() {
            for (int i=0;i<N;i++) { 
                cout << students[i].getImie() 
                << " "  << students[i].getNazwisko() 
                << " "  << students[i].getWiek() 
                << " "  << students[i].getGrupa()
                << " "  << students[i].numer_indeksu
                << endl;
            }
        }
      

};

int main() {
  studentSort group;
  group.fillArray();
  group.showArray();
  return 0;


}