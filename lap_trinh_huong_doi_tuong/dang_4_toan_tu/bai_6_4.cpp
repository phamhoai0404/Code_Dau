#include <iostream>
#include <stdio.h>
#include "conio.h"
#include<windows.h>
using namespace std;
class TAMTHUC
{
    private:
        float a,b,c;
    public:
        TAMTHUC operator-();
        TAMTHUC operator-(TAMTHUC y);
        TAMTHUC operator+(TAMTHUC y);
        friend istream& operator>>(istream& x, TAMTHUC &y);
        friend ostream& operator<<(ostream& x, TAMTHUC y);
};
TAMTHUC TAMTHUC::operator-()
{
    TAMTHUC tam;
    tam.a=-a;tam.b=-b;tam.c=-c;
    return tam;
}
TAMTHUC TAMTHUC :: operator+(TAMTHUC y)
{
    TAMTHUC tam;
    tam.a=a+y.a;
    tam.b=b+y.b;
    tam.c=c+y.c;
    return tam;
}
TAMTHUC TAMTHUC :: operator-(TAMTHUC y)
{
    TAMTHUC tam;
    tam.a=a-y.a;
    tam.b=b-y.b;
    tam.c=c-y.c;
    return tam;
}
istream&operator>>(istream& x, TAMTHUC &y)
{
    cout<<"\n \tNhap a:  ";      x>>y.a;
    cout<<"\n \tNhap b:  ";      x>>y.b;
    cout<<"\n \tNhap c:  ";      x>>y.c;
    return x;
}
ostream&operator<<(ostream& x, TAMTHUC y)
{
    x<<y.a<<"*x*x + "<<y.b<<"*x + "<<y.c;
    return x;
}
int main()
{
    TAMTHUC a,b;
    cout<<" Nhap gia tri cua tam thuc A: "<<endl;
    cin>>a;
    cout<<"\n Tam thuc vua nhap la: "<<a<<endl;
    a= - a;
    cout<<"\n Doi cua tam thuc A la: "<<a<<endl;
    cout<<"\n nhap tam thuc B: ";cin>>b;
    TAMTHUC T = a+b;
    TAMTHUC H = a-b;
    cout<<"\n Tong A va B: "<<a<<" + "<<b<<" = "<<T<<endl<<endl;
    cout<<"\n Hieu A va B: "<<a<<" - ("<<b<<") = "<<H<<endl;
    return 0;
}
