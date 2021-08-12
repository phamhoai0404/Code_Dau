#include<stdio.h>
void nhap(int a[], int &n)
{
	do{
		printf(" nhap n: "); scanf("%d",&n);
	}while( n>=100||n<=0);
	for( int i=0;i<n;i++)
	{
		printf(" a[%d]= ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[], int n)
{
	for( int i=0;i<n;i++)
	{
		printf( "%5d",a[i]);
	}
	
}
void dao( int a[], int na, int b[], int &nb)
{
	nb=0;
	for( int i=na-1;i>=0;i--)
	{
		b[nb++]=a[i];
		
	}
}
int main()
{
	int a[100];
	int b[100];
	int n,m;
	nhap(a,n);
	printf(" \n\n  mang la: ");
	xuat(a,n);
	dao(a,n,b,m);
	printf( " \n\n khi dao la: ");
	xuat(b,m);
	return 0;
	
}














