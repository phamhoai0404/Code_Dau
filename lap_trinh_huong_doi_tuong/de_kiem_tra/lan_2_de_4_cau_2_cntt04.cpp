#include <iostream>
#include <stdio.h>
#include "conio.h"
#include "iomanip"
#include "string.h"
#include<math.h>
using namespace std;
class PS
{
    private:
        int TS;
    public:
        PS operator+(PS y);
        PS operator-(PS y);
        char operator>(PS y);
        double GIATRI();
        friend istream& operator>>(istream& x, PS &y);
        friend ostream& operator<<(ostream& x, PS y);
};
PS PS::operator+(PS y)
{
    PS tg;
    tg.TS = TS+y.TS;
    return tg;
}
PS PS::operator-(PS y)
{
    PS tg;
    tg.TS = TS-y.TS;
    return tg;
}
char PS::operator>(PS y)
{
    char k;
    if(TS>y.TS)k='>';
    if(TS==y.TS)k='=';
    if(TS<y.TS)k='<';
    return k;
}
double PS::GIATRI()
{
    return (double) TS*TS*M_PI ;
}
istream&operator>>(istream& x, PS& y)
{
    cout<<"\n Nhap R:  ";      x>>y.TS;
    return x;
}
ostream&operator<<(ostream& x, PS y)
{
    x<<y.TS;
    return x;
}

int main()
{
    PS a, b;
    cout<<"Duong tron a: "<<endl;
    cin>>a;
    cout<<"Duong tron b: "<<endl;
    cin>>b;
    PS T=a+b;
    PS H=a-b;
    char SOSANH = a>b;
    cout<<"Tong dt la: "<<a.GIATRI()<<" + "<<b.GIATRI()<<" = "<<T.GIATRI()<<endl;
    cout<<"\nHieu dt la: "<<a.GIATRI()<<" - "<<b.GIATRI()<<" = "<<H.GIATRI()<<endl;
    cout<<"\n So sanh hai duong tron: a "<<SOSANH<<" b"<<endl;
    return 0;
}
