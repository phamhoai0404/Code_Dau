#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;
void nhap( float a[], int n)
{	
	for( int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]= ";
		cin>>a[i];
	}
}
void xuat(float a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];	
	}
}
float tongday(float a[], int n)
{
	float tong=0;
	for(int i=0;i<n;i++)
	{
		tong+=a[i];
	}
	return tong;
}			
void phan2( float a[], int n )
{	
	float b[100];
	int nb=0;
	for( int i=0;i<n;i++)
	{
		if(a[i]>=-4&&a[i]<=4)
		{
			b[nb++]=a[i];
		}
	}
	if(nb==0)cout<<"\n mang khong co phan tu thuoc doan [-4;4]";
	else{
		cout<<"\n phan tu thuoc doan[-4;4] la: ";
		xuat(b,nb);
		cout<<"\n S= "<<tongday(b,nb);
		cout<<"\n TBC= "<<tongday(b,nb)/nb;
	}				
}
void swap( float &a, float &b)
{
	float tam=a;a=b;b=tam;
}
void sapxep( float a[], int n)
{
	for( int i=0;i<n-1;i++)
	{
		int x=0;
		for( int j=n-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{ 	
				x=1;
				swap(a[j],a[j-1]);	
			}
		}
		if(x==0)return;
	}
}				
void chen( float a[], int &n, float x, int k)
{
	for( int i=n;i>k;i--)
	{
		a[i]=a[i-1];
	}
	a[k]=x;
	n++;
}			
void phancuoi( float a[], int &n)
{
	float x;
	cout<<"\n so can chen X= ";
	cin>>x;
	for( int i=0;i<n;i++)
	{
		if(a[i]<0)
		{	
			chen(a,n,x,i+1);
			i++;
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
	float *a =(float*)malloc(n*sizeof(float));
	nhap(a,n);
	cout<<"\n mang la: ";xuat(a,n);
	phan2(a,n);
	sapxep(a,n);
	cout<<"\n mang sau khi sap xep : ";
	xuat(a,n);
	phancuoi(a,n);
	cout<<"\n mang thay doi la: ";
	xuat(a,n);
	free(a);	
	return 0;
}
