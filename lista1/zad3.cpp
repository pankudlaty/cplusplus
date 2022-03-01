#include <stdio.h>
//#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

class quadraticEquation{

    private:
        double a, b, c, x0, x1, x2;
        int rootsNumber;
        void getData();
        void calculate();
    public:
        void showResult();
        quadraticEquation();
};

int main(){
    quadraticEquation equ1 = quadraticEquation();
    equ1.showResult();
    return 0;
}

void quadraticEquation::getData(){
    printf("Podaj wspolczynnik a: ");
    cin >> a;
    printf("Podaj wspolczynnik b: ");
    cin >> b;
    printf("Podaj wspolczynnik c: ");
    cin >> c;
    
}

void quadraticEquation::calculate(){
    double D = b * b - 4 * a * c;
    if (D > 0){
        rootsNumber = 2;
    } else if (D == 0){
        rootsNumber = 1;
    }else {
        rootsNumber = 0;
    }

    switch (rootsNumber)
    {
    case 2:
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
        break;
    case 1:
        x0 = (-b) / (2*a);
        break;
    default:
        break;
    }
}
void quadraticEquation::showResult(){
    switch (rootsNumber){
        case 2:
            printf("Pierwiastki rownania x1=%f oraz x2=%f\n", x1, x2);
            break;
        case 1:
            printf("Pierwiastek rownania x0=%f\n", x0);
            break;
        default:
            printf("Brak pierwiastkow rownania\n");
            break;

    }
}
quadraticEquation::quadraticEquation(){
    getData();
    calculate();
}