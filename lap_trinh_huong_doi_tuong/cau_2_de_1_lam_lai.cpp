#include<iostream>
#include<math.h>
using namespace std;
class diem
{
    private:
        int x,y,z;
    public:
        diem()
        {
            x=y=z=1;
        }
        diem ( int a, int b, int c)
        {
            x=a;y=b;z=c;
        }
        diem operator+(diem n)
        {
            diem k;
            k.x=x+n.x;
            k.y=y+n.y;
            k.z=z+n.z;
            return k;
        }
        friend istream& operator>>( istream& is, diem &n);
        friend ostream& operator<<( ostream& os, diem n);
};
istream& operator>>( istream& is, diem &n)
{
    cout<<"\n toa do  \n\tx: ";is>>n.x;
    cout<<"\ty: ";is>>n.y;
    cout<<"\tz: ";is>>n.z;
    return is;
}
ostream& operator<<( ostream& os, diem n)
{
    os<<" ( "<<n.x<<" , "<<n.y<< " , "<< n.z <<" )";
    return os;
}
int main()
{
    diem a,b;
    cin>>a>>b;
    cout<<a+b;
    return 0;
}
