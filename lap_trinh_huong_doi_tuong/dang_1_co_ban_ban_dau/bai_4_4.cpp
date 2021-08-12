#include<iostream>
#include<math.h>
using namespace std;
class so
{
    private:
        int a,b,c;
    public:
        void nhap();
        void xuat();
        void giai();
};
void so::nhap()
{
    cout<<"\n nhap vao lan luot a,b,c: ";cin>>a>>b>>c;
}
void so::xuat()
{
    cout<<"\n phuong trinhh la: " <<a<<"*x2 + "<<b<<"*x + "<<c<<" = 0 ";
}
void so::giai()
{
    if(a==0)cout<<"\n tro thanh phuong trinh bac 1 va x ="<<-c/b;
    else{
        float ta=b*b-4*a*c;
        if(ta<0)cout<<"\n phuong trinh vo nghiem !";
        else{
            if(ta==0)cout<<"\n phuong trinh  co nghiem kep x1=x2= "<<-b*1.0/(2*a);
            else{
                cout<<"\n phuong trinh co hai nghiem :";
                cout<<" x1 = "<<(-b+sqrt(ta))/(2*a);
                cout<<", x1 = "<<(-b-sqrt(ta))/(2*a);
        }
    }
}
int main()
{
    so x,b;
    x.nhap();
    x.xuat();
    x.giai();
    b.nhap();
    b.xuat();
    b.giai();
    return 0;
}
