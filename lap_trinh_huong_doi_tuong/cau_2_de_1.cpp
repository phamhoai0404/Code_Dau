#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
class diem
{
    private:
        int x,y,z;
    public:
        diem()
        {
            x=y=z=0;
        }
        diem(int a, int b, int c)
        {
            x=a;y=b;z=c;
        }
        diem operator+(diem n);
        friend istream& operator>>( istream& is, diem &n);
        friend ostream& operator<<( ostream& os, diem n);
        void xuat()
        {
             cout<< "Toa do: ("<<x<<" , "<<y<<" , "<<z<<" )";
        }

};
diem diem::operator+(diem n)
{
    diem k;
    k.x= x +n.x;
    k.y= y +n.y;
    k.z= z+n.z;
    return k;
}
istream& operator>>( istream& is, diem &n)
{
    cout<<"\n Toa do diem: ";is>>n.x>>n.y>>n.z;
    return is;
}
ostream& operator<<( ostream& os, diem n)
{
    os<< " toa do cua diem do la : ("<<n.x<<","<<n.y<<","<<n.z<<")";
    return os;
}
int main()
{

    diem b;
    diem a;
    cout<<"\n Toa diem A: ";cin>>a;
    cout<<"\n Toa diem B: ";cin>>b;
    diem t=a+b;
    cout<<"\n Tong toa do hai diem : ";cout<<t;
    return 0;
}
