#include <stdio.h>
//#include <conio.h>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int N=10;

class ArraySorting{
    private:
        int * arr;
        void readElements();
        void sortTab();
    public:
        void showArray();
        ArraySorting();
        ~ArraySorting();

};


int main(){
    ArraySorting sorting_one = ArraySorting();
    sorting_one.showArray();
    return 0;
}

ArraySorting::ArraySorting(){
    arr = new int [N];
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        arr[i] = 1 + rand() % 150;
    }
    
}
ArraySorting::~ArraySorting(){
    delete [] arr;
    printf("\n Usunieto tablice\n");
}

void ArraySorting::readElements()
{
    for(int i = 0; i< N; i++){
        int temp;
        scanf("%d",&temp );
        arr[i] = temp;
    }
}
void ArraySorting::sortTab(){
    sort(arr,arr + N);
}

void ArraySorting::showArray(){

    //readElements();
    sortTab();
    for (int i = 0; i < N; i++)
    {
        printf("%d \t", arr[i]);
    }
    
}