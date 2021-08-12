#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;
class ngay1
{
    private:
        int ngay;
        int thang;
        int nam;
    public:
        ngay1()
        {
            ngay=1;
            thang=12;
            nam=1;
        }
        ngay1( int x, int y, int z)
        {
            ngay=x;thang=y;nam=z;
        }
        void nhap();
        void xuat()
        {
            cout<< ngay <<"/"<< thang<<"/"<<nam;
        };
};
int main()
{


    ngay1 a=ngay1(13,22,33);
    a.xuat();


    ngay1 b;
    b.xuat();
    return 0;
}
