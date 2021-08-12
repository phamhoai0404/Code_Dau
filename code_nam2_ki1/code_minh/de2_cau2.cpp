#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;
void nhap( int a[], int n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]= ";
		cin>>a[i];
	}
}
void xuat(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];	
	}
}
int tongday(int a[], int n)
{
	float tong=0;
	for(int i=0;i<n;i++)
	{
		tong+=a[i];
	}
	return tong;
}		
void phan2( int a[], int n )
{
	int b[100];
	int nb=0;
	for( int i=0;i<n;i++)
	{
		if(a[i]%2==1)
		{
			b[nb++]=a[i];
		}
	}
	if(nb==0)cout<<"\n trong mang khong co so le!";
	else{
		cout<<"\n so le cua mang la: ";
		xuat(b,nb);
		cout<<"\n S= "<<tongday(b,nb);
		cout<<"\n TBC= "<<tongday(b,nb)/nb;
	}				
}
void swap( float &a, float &b)
{
	float tam=a;a=b;b=tam;
}
void sapxep( int a[], int n)
{
	for( int i=0;i<n-1;i++)
	{
		int x=0;
		for( int j=n-1;j>i;j--)
		{
			if(a[j]>a[j-1])
			{ 	
				x=1;
				swap(a[j],a[j-1]);	
			}
		}
		if(x==0)return;
	}
}				
void xoa( int a[], int &n, int k)
{
	for( int i=k;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}
void phancuoi( int a[], int &n)
{
	for( int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			xoa(a,n,i);
			i--;
		}
	}
}
int main()
{
	int n;
	do{
		cout<<"nhap N: ";
		cin>>n;
	}while(!(n>=5));		
	int *a =(int*)malloc(n*sizeof(int));
	nhap(a,n);
	cout<<"\n mang la: ";
	xuat(a,n);
	phan2(a,n);
	sapxep(a,n);
	cout<<"\n mang sau khi sap xep : ";
	xuat(a,n);
	phancuoi(a,n);
	cout<<"\n mang sau khi xoa phan tu chan la: ";
	xuat(a,n);
	free(a);	
	return 0;
}
