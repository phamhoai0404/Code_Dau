#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
void nhapmang ( int a[], int n )
{
	for( int i=0;i<n;i++)
	{
		printf("a[%d] =  ",i+1);
		scanf("%d",&a[i]);
	}
}
void xuatmang (int a[], int n)
{
    for( int i=0;i<n;i++)
	printf("\t %d", a[i]);
}
void xoa( int a[], int &n, int k)
{
	for( int i=k;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	n--;
}
void xoahet( int a[], int &n)
{
	int x;
	printf("\n nhap phan tu can xoa: ");scanf("%d",&x);
	for( int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			xoa(a,n,i);
			i--;
		}
	}
}
main()
{
	int n;
	printf("\n nhap so phan tu mang n= ");scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	nhapmang(a,n);printf("\n mang la: ");xuatmang(a,n);
	xoahet(a,n);
	printf("\n mang sau khi xoa la: ");xuatmang(a,n);
}
