#include <iostream>
#include <stdio.h>
#include "conio.h"
#include<windows.h>
using namespace std;
class SANPHAM
{
    private:
        float a;
    public:
        SANPHAM operator*(SANPHAM y);
        SANPHAM operator+(SANPHAM y);
        friend istream& operator>>(istream& x, SANPHAM&y);
        friend ostream& operator<<(ostream& x, SANPHAM y);
};
SANPHAM SANPHAM :: operator*(SANPHAM y)
{
    SANPHAM tam;
    tam.a = a *y.a;
    return tam;
}
SANPHAM SANPHAM :: operator+(SANPHAM y)
{
    SANPHAM tam;
    tam.a=a+y.a;
    return tam;
}
istream&operator>>(istream& x,SANPHAM &y)
{
    cout<<"\n \tGia:  ";      x>>y.a;
    return x;
}
ostream&operator<<(ostream& x, SANPHAM y)
{
    x<<y.a<<" 000 Dong ";
    return x;
}
int main()
{
    SANPHAM a,b;
    cout<<" Nhap san pham A: "<<endl;cin>>a;
    cout<<" Nhap san pham B: "<<endl;cin>>b;
    SANPHAM T = a*b;
    SANPHAM H = a+b;
    cout<<"\n Tong A va B: "<<a<<" * "<<b<<" = "<<T<<endl<<endl;
    cout<<"\n Tich A va B: "<<a<<" + "<<b<<" = "<<H<<endl;
    return 0;
}
