#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
int ktnt( int n)
{
	int dem=0;
	for( int i=1;i<=n;i++)
	{
		if(n%i==0)dem++;
	}
	if(dem==2)return 1;
	else return 0;
}
void tach (int a[], int na, int b[], int &nb, int c[], int &nc )
{
	nc=0; nb=0;
	for( int i=0;i<na;i++)
	{
		if(ktnt(a[i])==1)
		{
			b[nb++]=a[i];
		}else {c[nc++]=a[i];}
	}	
}

main()
{
	int na,nb,nc;
	printf("\n nhap so phan tu mang n= ");scanf("%d",&na);
	int *a=(int*)malloc(na*sizeof(int));
	int *b=(int*)malloc(na*sizeof(int));
	int *c=(int*)malloc(na*sizeof(int));
	nhapmang(a,na);
	printf("\n mang a la: ");xuatmang(a,na);
	tach(a,na,b,nb,c,nc);
	if (nb==0)
	{	printf("\n mang khong co so nguyen to !");
		
	}else {
		if( nb==na)	printf("\n mang toan la so nguyen to ! ");
		else 
			{		
				printf(" \n mang nguyen to la :  ");xuatmang(b,nb);
				printf("\n mang khong la so nguyen to la: ");xuatmang(c,nc);
			}
	}
}

