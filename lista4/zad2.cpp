#include "stdlib.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

class StudentEdukacja {
    private:
        string imie;
        string nazwisko;
        int wiek;
        string grupa;
        int numer_indeksu;
    public:
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
        string getGrupa() {
            return grupa;
        }
        void setGrupa(string grupa) {
            this->grupa = grupa;
        }
        int getNumerIndeksu() {
            return numer_indeksu;
        }
        void setNumerIndeksu(int numer_indeksu) {
            this->numer_indeksu = numer_indeksu;
        }
        void showData() {
            cout << getImie() 
                << " "  << getNazwisko() 
                << " "  << getWiek() 
                << " "  << getGrupa()
                << " "  << getNumerIndeksu()
                << endl;
        }
        StudentEdukacja(string imie, string nazwisko, int wiek, 
        string grupa, int numer_indeksu){
            setImie(imie);
            setNazwisko(nazwisko);
            setWiek(wiek);
            setGrupa(grupa);
            setNumerIndeksu(numer_indeksu);
        };
        StudentEdukacja(){};
       //friend ostream & operator << (ostream &out, const StudentEdukacja & obj) {
       //    out << obj.numer_indeksu << "\n" 
       //    << obj.imie << "\n"
       //    << obj.nazwisko << "\n"
       //    << obj.wiek << "\n"
       //    << obj.grupa << "\n"
       //    << endl;
       //    return out;
       //}
       //friend istream & operator >> (istream &in, StudentEdukacja &obj) {
       //    in >> obj.numer_indeksu;
       //    in >> obj.imie;
       //    in >> obj.nazwisko;
       //    in >> obj.wiek;
       //    in >> obj.grupa;
       //    return in;
       //}
};

class ioOperator {
    public:
        void czytaj_dane_z_klawiatury (StudentEdukacja &obj) {
            string imie, nazwisko, grupa;
            int nr_indeksu, wiek;
            cout<<"Podaj nr indeksu: ";
            cin>> nr_indeksu;
            obj.setNumerIndeksu(nr_indeksu);
            cout << "Podaj imie: ";
            cin>>imie;
            obj.setImie(imie);
            cout << "Podaj nazwisko: ";
            cin>>nazwisko;
            obj.setNazwisko(nazwisko);
            cout << "Podaj wiek: ";
            cin>>wiek;
            obj.setWiek(wiek);
            cout << "Podaj grupe: ";
            cin>>grupa;
            obj.setGrupa(grupa);
        }
        void zapisz_dane_do_pliku(StudentEdukacja  obj) {
            fstream out("students.dat",ios::out | ios::binary);
            out.write((char *)&obj, sizeof(StudentEdukacja));
            out.close();
        }
        void czytaj_dane_z_pliku(StudentEdukacja *obj) {
            fstream in("students.dat",ios::in | ios::binary);
            if(!in) {
                cout << "error opening file\n";
            }
            in.read((char*)obj,sizeof(StudentEdukacja));
            in.close();
        }
};

int main() {
    StudentEdukacja stu1;
    ioOperator ops;
    ops.czytaj_dane_z_klawiatury(stu1);
    stu1.showData();
    ops.zapisz_dane_do_pliku(stu1);
    StudentEdukacja *student1 = new StudentEdukacja();
    ops.czytaj_dane_z_pliku(student1);
    student1->showData();
    return 0;
}