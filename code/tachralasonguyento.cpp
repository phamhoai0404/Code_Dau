#include<stdio.h>
#include<math.h>
void nhap( int a[],int &n)
{
	printf(" so phan tu: ");scanf("%d",&n);
	for( int i=0;i<n;i++)
	{
		printf("phan tu thu %d la: ",i);
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
int LaSNT( int n)
{
	int dem=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)dem++;
	}
	if(dem==2)return 1;
	else return 0;
}
void tach( int a[],int na, int b[], int &nb)
{
	nb=0;
	for (int i=0;i<na;i++)
	{
		if(LaSNT(a[i])==1) b[nb++]=a[i];
		
	}
	
}
int main()
{
	int a[50]; int b[50];
	int x,y;
	nhap(a,x);
	printf("\n\n mang a la:");
	xuat(a,x);
	tach(a,x,b,y);
	printf("\n\n mang b gom cac so nguyen to la:");
	xuat (b,y);
	return 0;
	
}


