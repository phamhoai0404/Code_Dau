#include<stdio.h>
#include <math.h>
void nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf ("hay nhap so thu: %d ",i+1);
		scanf ("%d",&a[i]);
	}
}
void xuat( int a[], int n)
{
	for( int i=0;i<n; i++)
	printf("\t %d",a[i]);
}
int ktcp( int n)
{
	for( int i=1;i<=n;i++)
	{
		if(i*i==n)return 1;
	}
	return 0;
}
void timvitri( int a[], int n)
{
	int max=-1;
	for( int i=0;i<n;i++)
	{
		if(ktcp(a[i])==1)
		{
			max=a[i];
			break;
		}
	}
	if(max==-1)printf("\n mang vua nhap khong co so cp!");
	else{
		printf("\n vi tri cp lon nhat trong mang la: ");
		for(int i=0;i<n;i++)
		{
			if(max<a[i]&&ktcp(a[i])==1)max=a[i];
		}
		for( int i=0;i<n;i++)
		{
			if(a[i]==max) printf("\t %d",i+1);
		}		
	}
}
int main()
{
	int a[10], n;
	printf("\n nhap N:");scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	timvitri(a,n);
	return 0;
	}
	
	
