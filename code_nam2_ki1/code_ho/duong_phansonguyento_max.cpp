#include "stdio.h"
#include "stdlib.h"
#include "math.h"
void nhapmang (int n, int a[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(" nhap phan tu thu %d la: ",i);
		scanf("%d",&a[i]);
	}
}
void xuatmang (int n, int a[])
{
	int i; 
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
}
int ktsnt (int n)
{
	int d=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)d++;
	}
	if(d==2)return 1;
	return 0;
}

void maxnt (int n, int a[])
{
	int m,  x=-1;
	for(int i=0;i<n;i++)
	if(ktsnt (a[i])==1)
	{
		m=a[i];
		x=i;
		break;
	}
	if(x==-1)printf("\n mang vua nhap khong co so nguyen to!");
	else{
		for(int i=x;i<n;i++)
		{
			if(ktsnt(a[i])==1&&m<a[i])m=a[i];
		}
		printf("\n so nguyen to lon nhat trong mang la: %d",m);
	}
}
main()
{
	int n, *a;
	printf(" nhap phan tu mang n=");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	nhapmang(n,a);
	printf(" day vua nhap la: \n");
	xuatmang(n,a);
	maxnt(n,a);
}
