#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
using namespace std;
class hinhtron
{
    private:
        float r;
    public:
        float d()
        {
            return r*r*M_PI;
        }
        hinhtron()
        {
            r=0;
        }
        hinhtron(float a)
        {
            r=a;
        }
        float operator+(hinhtron a);
        float operator-(hinhtron a);
        string operator/(hinhtron a);
        friend ostream& operator<<( ostream& os, hinhtron a);
};
ostream& operator<<( ostream& os, hinhtron a)
{
    os<<" Dien tich: "<<a.d()<<" m^2";
}
float hinhtron::operator+(hinhtron a)
{
    return d()+a.d();
}
float hinhtron::operator-(hinhtron a)
{
    return d()-a.d();
}
string hinhtron::operator/(hinhtron a)
{
    string k;
    if(r>a.r)k=">";
    else if(r<a.r)k="<";
         else k="=";
    return k;
}
int main ()
{
    hinhtron a(10);
    hinhtron b(20);
    cout<<" a co "<<a<<endl<<endl;
    cout<<" b co "<<b;
    cout<<"\n hieu the tich: "<<a-b;
    cout<<"\n tong the tich :"<<a+b;
    cout<<"\n so sanh : a "<<  a/b <<" b";

    return 0;
}
