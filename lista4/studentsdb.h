#include "stdlib.h"
#include <iostream>
#include <string.h>
#include "stdlib.h"
#include <list>
#include <iterator>
#include <fstream>
#include <iomanip>

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
class StudentList {
    public:
        list<StudentEdukacja> studentDatabase;
        StudentList(){};
};

class Operator {
    public:
        void addStudent(StudentList *studentDB){
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
            
        };
        void deleteStudent(StudentList *studentDB) {
            int nr_indeksu;
            cout << "Podaj nr indeksu studenta, który ma zostać usunięty z listy: ";
            cin >> nr_indeksu;
            list<StudentEdukacja>::iterator i;
            for(auto i=studentDB->studentDatabase.begin(); i!=studentDB->studentDatabase.end();) {
                if(i->getNumerIndeksu() == nr_indeksu) {
                    i = studentDB->studentDatabase.erase(i);
                } else {
                    i++;
                }
            }
        }
        void sortStudentArray(StudentList *studentDB) {
            studentDB->studentDatabase.sort();

        };
        void listStudents(StudentList *studentDB) {
            list<StudentEdukacja>::iterator it;
            cout << left 
            << setw(15) << "Nr Indesku" 
            << setw(12) << "Imię" 
            << setw(16) << "Naziwsko" 
            << setw(8) << "Wiek"
            << "Grupa" 
            << endl; 
            cout << string(64, '-') << endl;
            for(it = studentDB->studentDatabase.begin(); it != studentDB->studentDatabase.end(); ++it) {
                
                cout << left 
                << setw(15) << it->getNumerIndeksu() 
                << setw(11) << it->getImie()
                << setw(16) << it->getNazwisko() 
                << setw(8) << it->getWiek()
                << it->getGrupa() 
                << endl;
            }
        }

};

class ioOperator {
    public:
    void writeFile(StudentList *studentDB) {
        ofstream out("students.txt");
        list<StudentEdukacja>::iterator it;
        for(it = studentDB->studentDatabase.begin(); it != studentDB->studentDatabase.end(); ++it) {
            out << *it;
        }
        out.close();
    }
    void readFile(StudentList *studentDB) {
        ifstream in("students.txt");
        if(!in) {
            cout << "Nie wczytano bazy danych z pliku, brak pliku bazy danych." << endl;
        } else {
            while (!in.eof()) {
                StudentEdukacja temp;
                in >> temp;
                studentDB->studentDatabase.push_back(temp);
        }
            studentDB->studentDatabase.pop_back(); //wyrzucenie pustej linii
            in.close();
            cout << "Pomyślnie wczytano plik z bazą danych" << endl;
        }
    }
};