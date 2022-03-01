#include <stdio.h>
//#include <conio.h>
#include <algorithm>

using namespace std;

const int N=10;

class ArraySorting{
    private:
        int tab[N];
        void readElements();
        void sortTab();
    public:
        void showArray();

};


int main(){
    ArraySorting sorting_one;
    sorting_one.showArray();
    return 0;
}
void ArraySorting::readElements()
{
    for(int i = 0; i< N; i++){
        int temp;
        scanf("%d",&temp );
        tab[i] = temp;
    }
}
void ArraySorting::sortTab(){
    sort(tab,tab + N);
}

void ArraySorting::showArray(){

    readElements();
    sortTab();
    for (int i = 0; i < N; i++)
    {
        printf("%d \t", tab[i]);
    }
    
}