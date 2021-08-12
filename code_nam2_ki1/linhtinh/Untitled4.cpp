#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
void nhap( int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}
void xuat( int a[], int n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}
}
void xoa(int a[],int &n)
{
	for(int i=0; i<n; i++)
	{
		while(a[i]%2==0)
		{
			for(int j=i; j<n; j++)
			{
				a[j] = a[j+1];
			}
			n--;
			a=(int *) realloc(a, n*sizeof(int ));
		}
	}
}
int main()
{
	int  *a; int n;
	cout<<"n="; cin>>n;
	a=new int[n];
//	for(int i=0; i<n; i++)
//	{
//		cout<<"a["<<i<<"]=";
//		cin>>a[i];
//	}
	nhap(a,n);
	xuat(a,n);
	xoa(a, n);
	cout<<"\n\n mang sau khi xoa la: ";
	xuat(a,n);
//	for(int i=0; i<n; i++)
//	cout<<a[i]<<" ";
	delete(a);
	return 0;
}
