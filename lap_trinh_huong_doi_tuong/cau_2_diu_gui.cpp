#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
class hcn
{
    private:
        float a,b;
    public:
        hcn()
        {
            a=b=0;
        }
        hcn(float x, float y)
        {
            a=x;b=y;
        }
        hcn operator*();
        friend istream& operator>>( istream& is, hcn &n);
        friend ostream& operator<<( ostream& os, hcn n);

};
hcn hcn::operator*()
{
    hcn k;
    k.a=a*2;
    k.b=b*2;
    return k;
}
istream& operator>>( istream& is, hcn &n)
{
    cout<<"\t chieu dai: ";is>>n.a;
    cout<<"\t chieu rong: ";is>>n.b;
    return is;
}
ostream& operator<<( ostream& os, hcn n)
{
    os<< " HCN "<<n.a<<" x "<<n.b ;
    return os;
}
int main()
{
    hcn a;
    cout<<"\n Hinh chu nhat a : "<<endl;
    cin>>a;
    a=*a;
    cout<<"\n Nhan doi chieu dai, chieu rong : "<<a<<endl<<endl;
    ofstream hoa("D:\\MON_HOC\\ee.txt",ios::out);
    hoa<<"\n Nhan doi chieu dai, chieu rong : "<<a<<endl<<endl;
    hoa.close();
    return 0;
}
