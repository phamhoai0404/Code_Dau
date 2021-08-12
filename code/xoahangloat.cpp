#include<stdio.h>
#include<math.h>
void nhap( int a[],int &n)
{
	do{
		printf(" nhap vao n: "); scanf(" %d",&n);
		if(n<=0||n>100)printf("nhap sai roi, vui long nhap lai, \n ");
	}while (n<=0||n>100);
	for( int i= 0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
	}
}
void xuat( int a[], int n)
{
	for( int i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
}
int Min( int a[], int n)
{
	int min=a[0];
	for( int i=1; i<n;i++)
	{
		if(min>a[i])min=a[i];
		
	}
	return min;	
}
void xoa( int a[], int &n, int vt)
{
	if( vt>=0&&vt<100)
	{
	 	for ( int j=vt; j<n-1;j++)
	 	{
	 		a[j]=a[j+1];
		}
		n--;
	}
}
int kiemtra( int a[], int n, int x)
{
	int dem=0;
	for( int i=0;i<n;i++)
	{
		if( a[i]==x)dem++;
	}
	return dem;
}

void XoaMin( int a[], int &n, int x)
{
	for( int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			xoa(a,n,i);
			i--;
		}
	}
}
int main()
{
	int a[100];
	int n;
	nhap(a,n);
	printf( "\n mang sau khi nhap la :");
	xuat(a,n);
	printf( " \n\n gia tri min la:%d ", Min(a,n));
	printf(" \n \n  so phan tu bang min la:%d ",kiemtra(a,n,Min(a,n)));
	XoaMin(a,n,Min(a,n));  
	printf(" \n mang sau khi xoa la: ");
	xuat(a,n);
	
	return 0;
}
	
























