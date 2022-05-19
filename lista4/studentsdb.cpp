#include "stdlib.h"
#include <iostream>
#include <string.h>
#include "stdlib.h"
#include <list>
#include <iterator>
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
        StudentEdukacja(string imie, string nazwisko, int wiek, 
        string grupa, int numer_indeksu){
            setImie(imie);
            setNazwisko(nazwisko);
            setWiek(wiek);
            setGrupa(grupa);
            setNumerIndeksu(numer_indeksu);
        };
        friend ostream& operator<<(ostream& os, const StudentEdukacja& student) {
            os << student.numer_indeksu
                << " "  << student.imie
                << " "  << student.nazwisko
                << " "  << student.wiek
                << " "  << student.grupa
                << endl;
            return os;
        }
        friend istream& operator>> (istream &in, StudentEdukacja &student) {
            in >> student.numer_indeksu;
            in >> student.imie;
            in >> student.nazwisko;
            in >> student.wiek;
            in >> student.grupa;
            return in;
        }
        bool operator<(const StudentEdukacja &student) {
            return (numer_indeksu < student.numer_indeksu);

        }
        bool operator==(const StudentEdukacja &student) {
            return (numer_indeksu == student.numer_indeksu);
        }
        bool operator!=(const StudentEdukacja &student) {
            return !operator==(student);
        }
        StudentEdukacja(){};
        
};
class StudentArray {
    public:
        list<StudentEdukacja> studentDatabase;
        StudentArray(){};
};

class Operator {
    public:
        void addStudent(StudentArray *studentDB){
            for (int i=0;i<3;i++) {
                string imie, nazwisko, grupa;
                int wiek, numer_indesku;
                cout << "Podaj nr indeksu: ";
                cin >> numer_indesku;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj nazwisko: "; 
                cin >> nazwisko;
                cout << "Podaj wiek: "; 
                cin >> wiek; 
                cout << "Podaj grupe: ";
                cin >> grupa; 
                studentDB->studentDatabase.push_back(StudentEdukacja(imie,nazwisko,wiek,grupa,numer_indesku));
            }
        };
        void deleteStudent(StudentArray *studentDB) {
            int nr_indeksu;
            cout << "Podaj nr indeksu studenta, który ma zostać usunięty z listy: ";
            cin >> nr_indeksu;
            list<StudentEdukacja>::iterator i;
            for(auto i=studentDB->studentDatabase.begin(); i!=studentDB->studentDatabase.end();) {
                if((*i).getNumerIndeksu() == nr_indeksu) {
                    i = studentDB->studentDatabase.erase(i);
                } else {
                    i++;
                }
            }
        }
        void sortStudentArray(StudentArray *studentDB) {
            studentDB->studentDatabase.sort();

        };
        void listStudents(StudentArray *studentDB) {
            list<StudentEdukacja>::iterator it;
            for(it = studentDB->studentDatabase.begin(); it != studentDB->studentDatabase.end(); ++it) {
                cout << *it;
            }
        }

};

class ioOperator {
    public:
    void writeFile(StudentArray *studentDB) {
        ofstream out("students.txt");
        list<StudentEdukacja>::iterator it;
        for(it = studentDB->studentDatabase.begin(); it != studentDB->studentDatabase.end(); ++it) {
            out << *it;
        }
        out.close();
    }
    void readFile(StudentArray *studentDB) {
        ifstream in("students.txt");
        while (!in.eof()) {
        StudentEdukacja temp;
        in >> temp;
        studentDB->studentDatabase.push_back(temp);
        }
        studentDB->studentDatabase.pop_back(); //wyrzucenie pustej linii
        in.close();
        
    }
};

int main(){
    StudentArray stuDB;
    Operator newop;
    ioOperator newioop;
    //newop.addStudent(&stuDB);
    newioop.readFile(&stuDB);
    newop.sortStudentArray(&stuDB);
    newop.listStudents(&stuDB);
    //newioop.writeFile(&stuDB);
    //newop.deleteStudent(&stuDB);
    //newop.listStudents(&stuDB);
    return 0;
}