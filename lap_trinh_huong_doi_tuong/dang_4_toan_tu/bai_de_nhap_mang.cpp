#include <iostream>
#include <stdio.h>
#include "conio.h"
#include<windows.h>
using namespace std;
class mang
{
    private:
        float a[30];
        int n;
    public:
        mang()
        {
            n=0;
        }
        mang operator+();
        mang operator-();
        friend istream& operator>>(istream& x, mang &y);
        friend ostream& operator<<(ostream& x, mang y);
};
mang mang:: operator+()
{
	mang x;
	x.n=n;
	for( int i=0;i<n;i++)	
    	x.a[i]=a[i];
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
        {
            if(x.a[j]<x.a[j-1])
            {
                float tam=x.a[j];
                x.a[j]=x.a[j-1];
                x.a[j-1]=tam;
                k=1;
            }
        }
        if(k==1)break;
    }
    return x;
}
mang mang:: operator-()
{
    mang x;
	x.n=n;
	for( int i=0;i<n;i++)	
    	x.a[i]=a[i];
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
        {
            if(x.a[j]>x.a[j-1])
            {
                float tam=x.a[j];
                x.a[j]=x.a[j-1];
                x.a[j-1]=tam;
                k=1;
            }
        }
        if(k==1)break;
    }
    return x;
}

istream&operator>>(istream& x, mang &a)
{
	cout<<"\n nhap vao n: "; x >> a.n;
    for( int i=0;i< a.n;i++)
    {
         cout<< "a["<<i+1<<"] = "; x>>a.a[i];
    }

    return x;
}
ostream&operator<<(ostream& x,mang a )
{
   for( int i=0;i<a.n;i++)
     x<<"\t "<<a.a[i];
    return x;
}
int main()
{
    mang a;
    cout<<" Nhap mang a: "<<endl;
    cin>>a; cout<<"\n mang a la: "<<a;
    a=+a; 
	cout<<"\n mang tang : "<<a;
    a=-a;
	cout<<"\n mang giam: "<<a;
   
    

    return 0;
}
