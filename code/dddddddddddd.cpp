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
void tach( int a[], int na, int b[], int &nb)
{
	nb=0;
	for( int i=0;i<na;i++)
	{
		if( a[i]>0) b[nb++]=a[i];
		
	}
	
	
}
int main()
{
	int a[100]; int b[100];
	int m,n;
	nhap(a,n);
	printf(" mang la: ");
	xuat(a,n);
	tach(a,n,b,m);
	printf(" mang moi:");
	xuat(b,m);
	return 0;
}
