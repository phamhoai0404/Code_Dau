#include<conio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
void nhapN( float &n)
{
	cout<<" nhap N : ";
	cin>>n;
}
void nhap( float a[], int  n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"phan tu thu "<<i+1<<" : ";
		cin>>a[i];
	}
}
void xuat( float a[], int n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];	
	}
}
float tinh( float a[], int n, float &x, float &k)
{
	float z=0,t=0;
	for( int i=0;i<n;i++)
	{	
		z+=a[i];
	}
	x=z/n;
	for( int i=0;i<n;i++)
	{	
		t+=pow(a[i]-x,2);
	}
	k=t/(n-1);
}			
void bai1()
{
	int n;
	float x,k;
	cout<<" nhap N: ";cin>>n;
	float  *a =(float*)malloc(n*sizeof(float));
	nhap(a,n);
	cout<<" \n mang la: ";
	xuat(a,n);
	tinh(a,n,x,k);
	cout<<"\n uoc luong ki vong: "<<x;
	cout<<"\n phuong sai: "<<k;
}
float tinhvohuong( float a[], float b[], int n)
{
	float s=0;
	for( int i=0;i<n;i++)
	{
		s+=a[i]*b[i];
	}
	return s;
}
double tinhfi( float a[], float b[], int n)
{
	int m;
	double s=0;
	cout<<"\n\n\n nhap m: ";cin>>m;
	if(m==1)
	{
		for( int i=0;i<n;i++)
		{	
			float x=fabs(a[i]-b[i]);
			s+=x;	
		}
	}
	if(m>=10)
	{
		float max=fabs(a[0]-b[0]);
		for( int i=1;i<n;i++)		
		{
			float x=fabs(a[i]-b[i]);		
			if(x>max)max=x;	
		}
		s=max;		
	}	
	if(m<=9&&m>=2)
	{
		float w=0;
		for( int i=0;i<n;i++)
		{
		 	w+=pow(a[i]-b[i],m);
		}
		s=pow ( w ,1.0/m);
	}
	return s;
}			
	
void bai2()
{
	int n ; double  x;
	cout<<" nhap N: ";cin>>n;
	float  *a =(float*)malloc(n*sizeof(float));
	float  *b =(float*)malloc(n*sizeof(float));
	cout<<"\n nhap cac phan tu mang a : \n";nhap(a,n);
	cout<<"\n mang a: ";xuat(a,n);
	cout<<"\n nhap cac phan tu mang b : \n";nhap(b,n);
	cout<<"\n mang b: ";xuat(b,n);
	cout<<"\n tich vo huong la: "<<tinhvohuong(a,b,n);
	x=tinhfi(a,b,n);
	cout<<"ket qua la: "<<x;
}
int main()
{
	do{
		int x;
		cout<<"\t\t\tHAY CHON MENU SAU ! ";
		cout<<"\n 1: Bai 1";
		cout<<"\n 2: Bai 2";
		cout<<"\n 3: Ket thuc chuong trinh! ";
		cout<<"\n\n Ban lua chon: ";
		cin>>x;
		switch(x)
		{
			case 1:bai1();break;
			case 2:bai2();break;
			case 3: return 0;
		}
		cout<<"\n Press  any key to continues...";
		getch();
		system("cls");
	}while(1);
}
	
