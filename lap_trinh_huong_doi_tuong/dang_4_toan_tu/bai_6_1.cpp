#include<iostream>
#include<math.h>
using namespace std;
class vecto
{
    private:
        float x,y;
    public:
        void nhap();
        void xuat();
    friend vecto operator+( vecto a, vecto b);
    friend vecto operator-( vecto a, vecto b);
};
void vecto::nhap()
{
    cout<<"\n nhap vao x,y: ";cin>>x>>y;
}
void vecto::xuat()
{
    cout<< "("<<x<<";"<<y<<")";
}
vecto operator+( vecto a, vecto b)
{
    vecto n;
    n.x=a.x+b.x;
    n.y=a.y+b.y;
    return n;
}
vecto operator-( vecto a, vecto b)
{
    vecto n;
    n.x=a.x-b.x;
    n.y=a.y-b.y;
    return n;
}
int main()
{
    vecto x,y,z,m;
    x.nhap();
    y.nhap();
    z=operator+(x,y);
    m=operator-(x,y);
    cout<<"\n\n toa do hai vecto la: ";x.xuat();y.xuat();
    cout<<"\n\n tong cua hai vecto la:";z.xuat();
    cout<<"\n\n hieu cua hai vecto la: ";m.xuat();
}
