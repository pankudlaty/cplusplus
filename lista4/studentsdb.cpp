#include "studentsdb.h"

using namespace std;

int main(){
    StudentList stuDB;
    Operator newop;
    ioOperator newioop;
    newioop.readFile(&stuDB);
    string option;
    while (true) {
        cout << 
        "<L> wylistowanie nazwisk, imion i wieku wszystkich studentów posortowanych według nr indeksu" << endl <<
        "<D> dodanie nowego studenta oraz wprowadzenie wszystkich cech go opisujących" << endl <<
        "<U> usunięcie studenta" << endl <<
        "<K> zakończenie programu i zapisanie bazy studentów do pliku" << endl;
        cout << "Podaj jedną z powyższych czynności: ";
        cin >> option;
        if (option == "K" || option == "k") {
            newioop.writeFile(&stuDB);
            return 0;
        } else if (option == "L" || option == "l") {
            newop.sortStudentArray(&stuDB);
            newop.listStudents(&stuDB);
        } else if (option == "D" || option == "d") {
            newop.addStudent(&stuDB);
        } else if (option == "U" || option == "u") {
            newop.deleteStudent(&stuDB);
        } else {
            cout << "Proszę podać jedną z dostępnych opcji." << endl;
        }
    }
}