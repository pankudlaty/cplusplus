//#include "stdafx.h"
#include <stdio.h>
//#include <conio.h>
#include <math.h>

const float PI = 3.14;

class kolo
{
friend void podaj_promien(kolo &, double);
private:
    double promien;
    double pole, obwod;
    void podaj_promien();
    void obliczaj();
    void pokaz_wynik();
public:
    void przetwarzaj();
};
void kolo::obliczaj() {
    pole = PI * pow(promien,2.0);
    obwod = 2* PI* promien;
}
void kolo::pokaz_wynik() {
    printf("\n Parametry kola: ");
    printf("\n Promien=%.31E", promien);
    printf("\n Pole=%.31E", pole);
    printf("\n Obwod=%31E\n\n", obwod);
}

void kolo::przetwarzaj() {
    obliczaj();
    pokaz_wynik();
}

int main() {
    kolo k1;
    podaj_promien(k1, 3.0);
    k1.przetwarzaj();
    return 0;
}
void podaj_promien(kolo &k, double r) {
    k.promien = r;
}