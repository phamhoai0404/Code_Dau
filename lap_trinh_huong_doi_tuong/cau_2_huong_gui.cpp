#include<iostream>
#include<math.h>
#include<conio.h>
#include<fstream>
using namespace std;
class mang
{
    private:
        int a[20];
        int n;
    public:
        mang()
        {
            n=0;
        }
        mang(int a11, int b, int c)
        {
          a[0]=a11; a[1]=b; a[2]=c;
        }
        friend istream& operator>>(istream& is , mang &k);
        friend ostream& operator<<(ostream& os , mang k);
        friend int minm(mang k);
        friend int min(mang k);
};
istream& operator>>(istream& is , mang &k)
{
    cout<<"\n nhap vao so phan tu mang: ";is>>k.n;
    for( int i=0;i<k.n;i++)
    {
        cout<<" phan tu thu "<<i+1 << " : " ;
        is>>k.a[i];
    }
    return is;
}
ostream& operator<<(ostream& os , mang k)
{
    os<<"\n Mang la: ";
    for( int i=0;i<k.n;i++)
        os<< "\t" <<k.a[i];
}
int  minm(mang k)
{
    int minn=k.a[0];
    for( int i=1;i<k.n;i++)
        if(minn>k.a[i])minn=k.a[i];
    return minn;
}
int  min(mang k)
{
    int minn=k.a[0];
    for( int i=1;i<k.n;i++)
        if(minn<k.a[i])minn=k.a[i];
    return minn;
}
int main()
{
    mang a;
    cin>>a;
    cout<<a;
    cout<<"\n min cua mang la: "<<minm(a);
    cout<<"\n max cua mang la: "<<min(a);
    ofstream ghi("yeu_cau.txt", ios:: app);
    ghi<<a;
    ghi<<"\n min cua mang la: "<<minm(a);
    ghi<<"\n max cua mang la: "<<min(a);
    ghi.close();

    return 0;
}
