#include<stdio.h>
#include<math.h>
void nhap(int &n)
{
	do{
		printf("nhap n:");scanf("%d",&n);
		if(n<5||n>30) printf("nhap sai roi,vui long nhap lai,");
	}
	while (n<5||n>30);
}
void nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
}
void sapxeptang(int a[],int n)
{

	int i,j,k;
	for(int i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
				
		}
	}
}
int main()
{
	int n;
	int a[100];
	nhap(n);
	nhap(a,n);printf("nhap mang:");
	xuat(a,n);
	sapxeptang(a,n); 
	printf("\n\n mang sau khi sap xep la :");
	xuat(a,n);
	return 0;
}
