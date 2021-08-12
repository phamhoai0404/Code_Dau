#include <iostream>
#include <stdio.h>
#include "conio.h"
#include<windows.h>
using namespace std;
class PHUONGTRINH
{
    private:
        float a,b;
    public:
        PHUONGTRINH(float x,float y)
        {
            a=x;
            b=y;
        }
        PHUONGTRINH()
        {
            a=0;
            b=0;
        }
        PHUONGTRINH operator-(PHUONGTRINH y);
        PHUONGTRINH operator+(PHUONGTRINH y);
        friend istream& operator>>(istream& x, PHUONGTRINH &y);
        friend ostream& operator<<(ostream& x, PHUONGTRINH y);
};
PHUONGTRINH PHUONGTRINH :: operator+(PHUONGTRINH y)
{
    PHUONGTRINH tam;
    tam.a=a+y.a;
    tam.b=b+y.b;
    return tam;
}
PHUONGTRINH PHUONGTRINH:: operator-(PHUONGTRINH y)
{
    PHUONGTRINH tam;
    tam.a=a-y.a;
    tam.b=b-y.b;
    return tam;
}
istream&operator>>(istream& x, PHUONGTRINH &y)
{
    cout<<"\n \tNhap a:  ";      x>>y.a;
    cout<<"\n \tNhap b:  ";      x>>y.b;
    return x;
}
ostream&operator<<(ostream& x,PHUONGTRINH  y)
{
    if(y.a==0)x<<y.b;
    else{
        if(y.b==0)x<<y.a<<"*x";
        else{
            if(y.b>0)x<<y.a<<"*x + "<<y.b;
            else x<<y.a<<"*x "<<y.b;
        }
    }
    return x;
}
int main()
{
    PHUONGTRINH a,b;
    cout<<" Nhap phuong trinh A co dang (a*x+b): "<<endl;
    cin>>a;

    cout<<"\n Nhap phuong trinh B co dang (a*x+b): "<<endl;
    cin>>b;

    PHUONGTRINH  T = a+b;
    PHUONGTRINH  H = a-b;

    cout<<"\n Tong A va B: "<<a<<" + "<<b<<" = "<<T<<endl<<endl;
    cout<<"\n Hieu A va B: "<<a<<" - ("<<b<<") = "<<H<<endl;
    return 0;
}
