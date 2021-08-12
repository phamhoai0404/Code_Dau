#include<stdio.h>
#include<math.h>
void giatriN( int &n)
{
	do{
		printf(" nhap N: "); scanf(" %d",&n);
		if(!(2<=n&&n<=10))printf(" sai roi, ");
	}while(!(2<=n&&n<=10) );
}
void nhap( int a[], int n)
{
	for( int i=0;i<n;i++)
	{
		printf(" thu %d la:  ", i);
		scanf("%d", &a[i]);
		
	}
}
void xuat(int a[], int n)
{
	for( int i=0;i<n;i++)
	{
		printf(" %5d ", a[i]);
	}
}
void tim( int a[], int n)
{
	int k;
	printf(" \n\n so can tim la: "); scanf(" %d",&k);
	int dem=0;
	for( int i=0;i<n;i++)
	{
		if( a[i]==k)dem++;
	}
	printf("\n\n  so lan xuat hien %d la: %d",k, dem);
	
}
void ghep( int a[],  int b[], int n, int c[], int &nc)
{
	nc=0;
	for( int i=0;i<n;i++ )
	{
		c[nc++]=a[i];
	}
	for( int i=0;i<n;i++)
	{
		c[nc++]=b[i];
	}
}
void  timvasua( int a[], int n)
{
	int x,k;
	printf( " \n\n so can tim k la:  ");scanf("%d",&k);
	printf( " \n \n so thay x the: "); scanf("%d",&x);
	for( int i=0;i<n;i++)
	{
		if( a[i]==k)
		{
			a[i]=x;
		}
}
}
void xoadau( int a[], int &n)
{
	int k;
	printf("\n\n so can xoa o dau la: "); scanf("%d",&k);
	for( int i=0;i<n;i++)
	{
		if( a[i]==k)
		{
			for( int j=i;i<n-1;i++)
			{
				a[i]=a[i+1];
			}
			n--;
			break;
		}
	}
}
void themvao( int a[], int &n)
{
	int k;
	printf("\n\n nhap gia tri can them: ");scanf("%d",&k);
	for( int i=n;i>n-3;i--)
	{
		a[i]=a[i-1];
	}
	a[n-3]=k;
	n++;
}
int main()
{
	int a[100],b[100],c[100];
	int n,nc ;
	giatriN(n);
	nhap(a,n);
	printf(" \n\n mang a la : ");xuat(a,n);printf("\n\n");
	nhap(b,n);
	printf("\n \n  mang b la: ");xuat(b,n);printf("\n\n");
	ghep(a,b,n,c,nc);
	printf(" \n\n mang c la : ");
	xuat(c,nc);
	tim(c,nc);
	timvasua(c,nc);
	printf(" mang moi sau khi sua la: ");
	xuat(c,nc);
	xoadau(c,nc);
	printf( " mang sau khi xoa la: ");
	xuat(c,nc);
	themvao(c,nc);
	printf(" mang sau khi them vao la: ");
	xuat(c,nc);
	return 0;
}
