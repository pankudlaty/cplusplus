#include "stdlib.h"
#include <iostream>
#include <string.h>
#include <strings.h>
#include "stdlib.h"
const int N = 5;
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
        StudentEdukacja(string imie, string nazwisko, int wiek, 
        string grupa, int numer_indeksu){
            setImie(imie);
            setNazwisko(nazwisko);
            setWiek(wiek);
            setGrupa(grupa);
            setNumerIndeksu(numer_indeksu);
        };
        
};
class StudentArray {
    friend class Operator;
    friend class ioOperator;
    private:
        StudentEdukacja studentDatabase[N];
};

class Operator {
    private:
        void addStudent();
        void deleteStudent();
        void sortStudentArray();

};

class ioOperator {
    private:
    void writeFile();
    void readFile();

};

int main(){
    return 0;
}



