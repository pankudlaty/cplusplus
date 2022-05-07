
#include <stdio.h>


class obwod
{
    protected:
        double e,r0,r1,r2;
        double u0,u,i,i1,i2,p,p0,p1,p2;
        void oblicz();
    public:
        void wyniki();
        obwod(double,double,double,double);
};
void obwod::oblicz(){
    i=e/(r0+r1*r2/(r1+r2));
    u0=i*r0;
    u=e-u0;
    i1=u/r1;
    i2=u/r2;
    p0=u0*i;
    p1=u*i1;
    p2=u*i2;
    p=e*i;
}
void obwod::wyniki()
{
    oblicz();
    printf("\nDane:\ne =%.3le r0=%.3le r1=%.3le r2=%.3le",e,r0,r1,r2);
    printf("\nWyniki obliczen:");
    printf("\ni =%.3le i1=%.3le i2=%.3le",i,i1,i2);
    printf("\nu0=%.3le u =%.3le",u0,u);
    printf("\np0=%.3le p1=%.3le p2=%.3le p =%.3le\n",p0,p1,p2,p);
}

//definicja konstruktora
obwod::obwod(double _e,double _r0,double _r1,double _r2):e(_e),r0(_r0),r1(_r1),r2(_r2) {}

class obwod1:public obwod
{
    private:
        double umax,umin,imax,imin;
        double de,dr;
        void oblicz1();
    public:
        void wyniki1();
        obwod1(double,double,double,double,double,double);
};
void obwod1::oblicz1()
{
    double r=r1*r2/(r1+r2);
    double rm=1.0-dr/100.0;
    double rp=1.0+dr/100.0;
    double em=1.0-de/100.0;
    double ep=1.0+de/100.0;
    imax=ep*e/(rm*(r0+r));
    imin=em*e/(rp*(r0+r));
    umax=ep*e-rm*r0*ep*e/(rm*r0+rp*r);
    umin=em*e-rp*r0*em*e/(rp*r0+rm*r);
} 
void obwod1::wyniki1()
{
    oblicz1();
    printf("\nDane:\nde=%.3le dr=%.3le ",de,dr);
    printf("\nWyniki obliczen:");
    printf("\numin=%.3le umax=%.3le",umin,umax);
    printf("\nimin=%.3le imax=%.3le",imin,imax);
    printf("\n");
}

//Definicja konstruktora klasy pochodnej:
obwod1::obwod1(double _e,double _r0,double _r1,double _r2,double _de, double _dr):obwod(_e,_r0,_r1,_r2), de(_de), dr(_dr) {}


int main()
{
    obwod1 circuit=obwod1(12,1,10,20,5,10);
    circuit.wyniki();
    circuit.wyniki1();
    return 0;
}