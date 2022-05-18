#include "stdlib.h"
#include <iostream>
#include <string.h>
#include <strings.h>
#include "stdlib.h"
const int N = 3;
using namespace std;

class StudentEdukacja {
    friend class StudentArray;
    private:
        string imie;
        string nazwisko;
        int wiek;
        string grupa;
        int numer_indeksu;
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
    public:
        StudentEdukacja(string imie, string nazwisko, int wiek, 
        string grupa, int numer_indeksu){
            setImie(imie);
            setNazwisko(nazwisko);
            setWiek(wiek);
            setGrupa(grupa);
            setNumerIndeksu(numer_indeksu);
        };
        void showData() {
                cout << getImie() 
                << " "  << getNazwisko() 
                << " "  << getWiek() 
                << " "  << getGrupa()
                << " "  << getNumerIndeksu()
                << endl;
        }
        StudentEdukacja(){};
        
};
class StudentArray {
    public:
        StudentEdukacja studentDatabase[N];
        StudentArray(){};
};

class Operator {
    public:
        void addStudent(StudentArray *studentDB){
            for (int i=0;i<N;i++) {
                string imie, nazwisko, grupa;
                int wiek, numer_indesku;
                cout << "Podaj dane studenta: ";
                cin >> imie, nazwisko, wiek, grupa, numer_indesku; 
                studentDB->studentDatabase[i] = StudentEdukacja(imie,nazwisko,wiek,grupa,numer_indesku);
            }
        };
        void deleteStudent();
        void sortStudentArray();
        void listStudents(StudentArray *studentDB) {
            for (int i = 0; i < N ; i++) {
                studentDB->studentDatabase[i].showData();
            }
             
            
        }

};

class ioOperator {
    private:
    void writeFile();
    void readFile();

};

int main(){
    StudentArray stuDB;
    Operator newop;
    newop.addStudent(&stuDB);
    newop.listStudents(&stuDB);
    return 0;
}