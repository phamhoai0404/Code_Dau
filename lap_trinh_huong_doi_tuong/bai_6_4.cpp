#include<iostream>
#include<math.h>
using namespace std;
class tamthuc
{
    private:
        float a,b,c;
    public:
        tamthuc()
        {
            a=b=c=0;
        }
        tamthuc(float x, float y, float z)
        {
            a=x;b=y;c=z;
        }
        tamthuc operator*();
        tamthuc operator+(tamthuc n);
        tamthuc operator-(tamthuc n);
        friend ostream&  operator<<( ostream& os , tamthuc n);

};
ostream&  operator<<( ostream& os , tamthuc n)
{
    os<< n.a<<"x^2 + "<<n.b <<"x + "<<n.c;
    return os;
}
tamthuc tamthuc::operator*()
{
    tamthuc k;
    k.a=-a;
    k.b=-b;
    k.c=-c;
    return k;
}
