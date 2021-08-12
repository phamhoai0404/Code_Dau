#include "stdio.h"
#include "math.h"
void nhapmang (int n,int a[])
{
	int i;
	for (i=0;i<n;i++)
	{
		printf ("hay nhap so thu: %d ",i);
		scanf (" %d",&a[i]);
	}
}
void xuatmang ( int n, int a[])
{
	int i;
	for (i=0;i<n; i++)
	printf("\t%d",a[i]);
}
int ktsnt (int n)
{
	int i,d=0;
	for (i=1;i<=n;i++)
	if(n%i==0)d++;
	if (d==2) return 1;
	return 0;
}
void chen( int &n , int a[], int x, int k)
{
	for( int i=n;i>x;i--)
	{
		a[i]=a[i-1];
	}
	a[x]=k;
	n++;
}
void chenmang( int &n, int a[])
{
	int k=-1, min;
	for(int i=0;i<n;i++)
	{
		if(ktsnt(a[i])==1)
		{	
			min=a[i];
			k=i;
		}
	}
	if(k==-1)printf("\n mang  khong co so nguyen to nen khong phai lam tiep !");
	else{
		for(int i=k+1;i<n;i++)
		{
			if(ktsnt(a[i])==1&&a[i]<min)min=a[i];
		}
		do{
			printf("\n nhap vao tri k can chen: ");
			scanf("%d",&k);
			if(!(k>=1&&k<=0))printf("\n khong co vi tri nay, lam lai !");
		}while(!(k>=1&&k<=n));
		int x=k-1;
		chen(n,a,x,min);
	}
	}
main()
{
	 int n, a[20];
	 printf("\n hay nhap so phan tu mang n =");
	 scanf("%d",&n);
	 nhapmang(n,a);
	 printf("\n mang vua nhap la :\n");	
	 xuatmang(n,a);
	 chenmang(n,a);
	 printf("\n mang sau khi chen la: ");
	 xuatmang(n,a);
	 }
	 
