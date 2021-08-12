#include<stdio.h>
#include<math.h>
int giatriN( int &n)
{
	do{
		printf(" nhap N: "); scanf("%d",&n);
		if(!((n>=5)&&(n<=30)))printf(" nhap lai, ");
	}while(!((n>=5)&&(n<=30)));
}

void nhap( int a[],int n)
{
	for( int i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
		
	}
}

void xuat( int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",a[i]);
		
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
float tinh( int a[], int na, int n)
{
	float tong=0;
	float dem=0;
	for( int i=0;i<na;i++)
	{
		if( a[i]%2==0&&a[i]%n==0)
		{
		
			tong+=a[i];
			dem++;
			
		}
	}
	if (dem==0) return 0;
	else return tong/dem;
	
}
int SNT( int x)
{
	int dem=0;
	for( int i=1;i<x;i++)
	{
		if( x%i==0)dem++;
		
	}
	if( dem==2)return 1;
	else return 0;
}
int  tongkoSNT( int a[], int n)
{
	int tong=0;
	for( int i=0;i<n;i++)
	{
		if( SNT(a[i])==0)tong+=a[i];
	}
	return tong;
}
int main()
{
	int a[100],b[100];
	int N,nb;
	float x;
	giatriN(N);
	nhap(a,N);
	printf(" mang la: ");
	xuat(a,N);
	dao(a,N,b,nb);
	printf("\n \n  mang dao la: ");
	xuat(b,nb);
	x=tinh(a,N,N);
	if( x==0)printf("\n\n khong co gia tri TBC !");
	else printf( " \n\n TBC theo yeu cau la: %f",x);
	
	printf(" \n \n tong khong phai la SNT : %d",tongkoSNT(a,N));
	return 0;
	
	
}












