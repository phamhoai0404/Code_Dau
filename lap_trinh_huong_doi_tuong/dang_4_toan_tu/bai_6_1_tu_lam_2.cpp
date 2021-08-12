#include <iostream>
#include <stdio.h>
#include "conio.h"
#include<windows.h>
using namespace std;
class TOADO
{
    private:
        float a,b;
    public:
        TOADO operator-(TOADO y);
        TOADO operator+(TOADO y);
        friend istream& operator>>(istream& x, TOADO &y);
        friend ostream& operator<<(ostream& x, TOADO y);
};
TOADO TOADO :: operator-(TOADO y)
{
    TOADO tam;
    tam.a=a-y.a;
    tam.b=b-y.b;
    return tam;
}
TOADO TOADO :: operator+(TOADO y)
{
    TOADO tam;
    tam.a=a+y.a;
    tam.b=b+y.b;
    return tam;
}
istream&operator>>(istream& x,TOADO &y)
{
    cout<<"\n \tNhap x:  ";      x>>y.a;
    cout<<"\n \tNhap y:  ";      x>>y.b;
    return x;
}
ostream&operator<<(ostream& x,TOADO y)
{
    x<<"( "<<y.a<<", "<<y.b<<" )";
    return x;
}
int main()
{
    TOADO a,b;
    cout<<" Nhap vecto A: "<<endl;cin>>a;
    cout<<" Nhap vecto B: "<<endl;cin>>b;
    TOADO T = a+b;
    TOADO H = a-b;
    cout<<"\n Tong A va B: "<<a<<" + "<<b<<" = "<<T<<endl<<endl;
    cout<<"\n Hieu A va B: "<<a<<" - ("<<b<<") = "<<H<<endl;
    return 0;
}
