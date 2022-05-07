#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;
const int N=10;

class abstract {
    protected:
        int t[N];
        char napis[80];
    public:
        void zaptab();
        void poktab();
        void virtual sortuj()=0;
};

void abstract::zaptab() {
    srand(time(NULL));
    int i;
    for (int i=0;i<N;i++) {
        t[i] = rand()%100;
    }
}
void abstract::poktab() {
    puts(napis);
    for (int i=0;i<N;i++) { 
        cout.width(4);
        cout << t[i];
    }
    cout << "\n\n";
}

class bubble: public abstract {
    public:
void sortuj();
};
void bubble::sortuj() {
    strcpy(napis,"Metoda sortowania: Bubble sort");
    int buf;
    int k;
    for(k=0;k<N-1;k++) {
        for(int j=k+1;j<N;j++) {
            if(t[k]>t[j]){
                buf=t[k];
                t[k]=t[j];
                t[j]=buf;
            }
        }
    }
}
class insert: public abstract{
    public:
void sortuj();
};
void insert::sortuj() {
    int i,j,temp;
    strcpy(napis,"Metoda sortowania: Insert sort");
        for(i=1;i<N;i++) {
            j=i;
            temp=t[j];
            while(j>0 && t[j-1]>temp)
            {
                t[j]=t[j-1];
                j--;
            }
            t[j]=temp;
        }
} 
class select1: public abstract {
    public:
    void sortuj();
};
    void select1::sortuj() {
    int i,j,minpos,buf;
    strcpy(napis,"Metoda sortowania: Select sort");
    for (i=0; i<N-1;i++)
    {
        minpos=i;
            for(j=i+1;j<N;j++) {
                if(t[j]<t[minpos]) {
                    minpos=j;
                }
                buf=t[i];
                t[i]=t[minpos];
                t[minpos]=buf;
        }
    }
}
void wybor_metody(abstract &obiekt) { 
    obiekt.zaptab();
    obiekt.sortuj();
    obiekt.poktab();
}

int main()
{
    bubble obiekt1;
    insert obiekt2;
    select1 obiekt3;
    wybor_metody(obiekt1);
    wybor_metody(obiekt2);
    wybor_metody(obiekt3);
    return 0;
}