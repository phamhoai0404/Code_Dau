#include<iostream>
#include<math.h>
#include<string.h>
#include<conio.h>
using namespace std;
class sophuc
{
    private:
        float a, b;
    public:
        sophuc()
        {
            a=b=0;
        }
        sophuc(float x, float y)
        {
            a=x;b=y;
        }
        friend istream& operator>>( istream& is, sophuc &n);
        friend ostream& operator<<( ostream& os, sophuc k);
        sophuc operator+( sophuc n);
        sophuc operator*();
        string operator-( sophuc n);
};
istream& operator>>( istream& is, sophuc &n)
{
    cout<<"\n\t phan thuc: ";is>>n.a;
    cout<<"\t phan ao: ";is>>n.b;
    return is;
}
ostream& operator<<( ostream& os, sophuc n)
{
    os<< n.a <<" + "<<n.b<<"i" ;
    return os;
}
sophuc sophuc::operator+(sophuc n)
{
    sophuc k;
    k.a=a+n.a;
    k.b=b+n.b;
    return k;
}
sophuc sophuc:: operator*()
{
    sophuc k;
    k.a=-a;
    k.b=-b;
    return k;
}
string sophuc::operator-(sophuc n)
{
    string k;
    if(a>n.a)k=">";
    else if(a<n.a)k="<";
         else if(b>n.b)k=">";
              else if(b<n.b)k="<";
                   else k="=";
    return k;
}
int main()
{
   sophuc a[30];

    int n;
    do{
        cout<<"\n nhap vao so luong so phuc la: ";cin>>n;
        if(!(n>=0))cout<<"\n vui long nhap lai, ";
    }while(!(n>=0));
    sophuc k;
    for( int i=0;i<n;i++)
    {
        cout<<"\n so phuc thu : "<<i+1;
        cin>>a[i];cout<<"\n "<<a[i];
        k= k + a[i] ;
    }
    cout<<"\n tong tat ca so phuc la: "<<k;
    getch();
    return 0;

}
