#include<iostream>
#include<cstdlib>
using namespace std;
void nhap( float *&a, int &n)
{
	do{
		cout<<"\n Nhap N: ";cin>>n;
		if(!(n>=3))cout<<" Vui long nhap lai, ";
	}while(!(n>=3));
	a= (float *)malloc( n*sizeof(float));
	for( int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]=";
		cin>>a[i];
	}
}
void xuat( float *a, int n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"\t\t"<<a[i];	
	}
}
void y2( float *a, int n)
{
	int dem=-1; float tong =0;
	for ( int i=0;i<n;i++)
	{
		if(a[i]>=-4&&a[i]<=4)
		{	
			dem++;
			break;
		}
	}
	if(dem==-1)printf("\n mang vua nhap khong co so nao thuoc khoang [-4;4] ! ");
	else{
		cout<<"\n nhung so thuoc doan [-4;4] la: ";
		for( int i=0;i<n;i++)
		{
			if(a[i]>=-4&&a[i]<=4)
			{	
				cout<<"\t "<<a[i];
				dem++;
				tong+=a[i];
			}
		}
		cout<<"\n tong cua cac so do la: "<<tong;
		cout<<"\n TBC : "<<tong/dem;
	}
}
float max(float *a, int n)
{
	float maxx=a[0];
	for(int i=1;i<n;i++)
	{	
		if(a[i]>maxx)maxx=a[i];
	
	}
	return maxx;
}
void y3( float *&a, int &n)
{
	float ma=max(a,n); int dem=0;
	for( int i=0;i<n;i++)
	{
		if(a[i]==ma)dem++;
	}
	int x=n+dem;
	a=(float *)realloc(a,x*sizeof(float));//neu muon chen thi cap phat dong truoc khi no lay
	for( int i=n;i<x;i++)
	{
		a[n++]=ma;
	}
	cout<<"\n mang la: ";xuat(a,n);
}
void chen ( float *&a, int &n, float x, int k)
{
	a=(float *)realloc(a, (n+1)*sizeof(float));
	for(int i=n;i>k;i--)
	{
		a[i]=a[i-1];
	}
	a[k]=x;
	n++;
}
void y4( float *&a, int &n)
{
	float x;
	cout<<"\n nhap vao gia tri can chen: "; cin>>x;
	for( int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			chen(a,n,x,i);
			i++;
		}
	}
	cout<<"\n mang sau khi chen la: ";xuat(a,n);
}
void xoa( float *&a, int &n, int k)
{
	for( int i=k;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
	a=(float *)realloc( a, n*sizeof(float));
}
void xoamang(float *&a, int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			xoa(a,n,i);
			i--;
		}
	}
	cout<<"\n mang sau khi xoa bo nhung xoa am la: ";xuat(a,n);
}
main()
{
	float *a;int n;
	nhap(a,n);
	cout<<"\n mang la: ";
	xuat(a,n);
	y2(a,n);
	y3(a,n);
	y4(a,n);
	xoamang(a,n);
	free(a);
}













