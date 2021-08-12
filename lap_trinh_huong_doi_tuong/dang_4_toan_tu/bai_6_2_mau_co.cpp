#include <iostream>
#include <stdio.h>
#include "conio.h"
#include "iomanip"
#include "string.h"
using namespace std;
class PS
{
    private:
        int TS, MS;
    public:
        PS operator+(PS y);
        PS operator-(PS y);
        PS operator*(PS y);
        PS operator/(PS y);
        double GIATRI();
        friend istream& operator>>(istream& x, PS &y);
        friend ostream& operator<<(ostream& x, PS y);
};
PS PS::operator+(PS y)
{
    PS tg;
    tg.TS = TS*y.MS + MS*y.TS;
    tg.MS = MS*y.MS;
    return tg;
}
PS PS::operator-(PS y)
{
    PS tg;
    tg.TS = TS*y.MS - MS*y.TS;
    tg.MS = MS*y.MS;
    return tg;
}
PS PS::operator*(PS y)
{
    PS tg;
    tg.TS = TS*y.TS;
    tg.MS = MS*y.MS;
    return tg;
}
PS PS::operator/(PS y)
{
    PS tg;
    tg.TS = TS*y.MS;
    tg.MS = MS*y.TS;
    return tg;
}
double PS::GIATRI()
{
    return (double) TS/MS;
}
/*void PS::nhap_phanso( PS &ps)
{

	cout<<"\n Nhap tu so: ";
	cin>>ps.TS;
	cout<<"\n Nhap mau so: ";
	cin>>ps.MS;
}*/
istream&operator>>(istream& x, PS& y)
{
    cout<<"\n Nhap tu so:  ";      x>>y.TS;
    cout<<"\n Nhap mau so: ";      x>>y.MS;
    return x;
}
/*void PS:: xuat_phanso( PS &ps)
{

	cout<<ps.TS<<"/"<<ps.MS;
}*/
ostream&operator<<(ostream& x, PS y)
{
    x<<y.TS<<"/"<<y.MS;
    return x;
}

int main()
{
    PS a, b;
    cout<<"Nhap phan so thu nhat: "<<endl;
    cin>>a;
    cout<<"Nhap phan so thu 2: "<<endl;
    cin>>b;
    PS T=a+b;
    PS H=a-b;
    PS TICH = a*b;
    PS THUONG = a/b;
    cout<<a<<" + "<<b<<" = "<<T<<" = "<<T.GIATRI()<<endl;
    cout<<a<<" - "<<b<<" = "<<H<<" = "<<H.GIATRI()<<endl;
    cout<<a<<" * "<<b<<" = "<<TICH<<" = "<<TICH.GIATRI()<<endl;
    cout<<a<<" / "<<b<<" = "<<THUONG<<" = "<<THUONG.GIATRI()<<endl;
    return 0;
}
