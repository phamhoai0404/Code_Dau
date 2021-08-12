#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void nhap(int *&a,int &n)
{
	a=(int *)malloc(n*sizeof(int ));
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]=";
		cin>>a[i];
	}
}
void xuat(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
	  cout<<"\t"<<a[i];
	}
}
int tongday(int *a,int n)
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		tong+=a[i];
	}
	return tong;
}
void phan1(int *a,int n)
{
	int b[100];
	int nb=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=-4&&a[i]<=4)
		{
			b[nb++]=a[i];
		}
	}
	if(nb==0)
	{
		cout<<"khong co phan tu thuoc doan [-4,4]";
		
	}
	else{
		cout<<"\n co phan tu thuoc doan [-4,4] la:";
		xuat(b,nb);
		cout<<"\n S="<<tongday(b,nb);
		cout<<"\n TBC="<<tongday(b,nb)/nb;
	}
}
void sapxep(int *a,int n)
{
	for(int i=0;i<n;i++)
	   for(int j=n-1;j>i;j--)
	     {
		 if(a[j]<a[j-1])
	     {
	     	int tag=a[j];
	     	a[j]=a[j-1];
	     	a[j-1]=tag;
	     	
		 }
	}
}
void chen(int *a,int &n ,int x,int vitri)
{
	a=(int *)realloc(a,n*sizeof(int ));
	if(vitri>0&&vitri<n)
	{
		for(int i=n;i>vitri;i--)
		{
			a[i]=a[i-1];
		}
		a[vitri]=x;
		n++;
		
	}
}
void chenam(int *a,int &n)
{
	int x;
	cout<<"\nnhap so can chen:";cin>>x;
	for(int i=0;i<n;i++)
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
	int *a;int n;
	do{
		cout<<"\n nhap gia tri nguyen duong n:";
		cin>>n;
		if(n<5) cout<<"nhap sai roi vui long nhap lai!";
	}
	while(n<5);
	nhap(a,n);
	cout<<"\n mang sau khi nhap la:";
	xuat(a,n);
	tongday(a,n);
	phan1(a,n);
	sapxep(a,n);
	cout<<"\nmang sau khi sap xep la:";
	xuat(a,n);
	chenam(a,n);
	cout<<"\n mang sau khi chen la:";
	xuat(a,n);
}

