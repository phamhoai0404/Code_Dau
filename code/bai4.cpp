#include<stdio.h>
#include<math.h>
int giatriN( int &n)
{
	do{
		printf(" nhap N: "); scanf("%d",&n);
		if(!((n>=0)&&(n<=10)))printf(" nhap lai, ");
	}while(!((n>=0)&&(n<=10)));
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
int  tach( int a[], int na, int b[], int &nb)
{
	nb=0;
	int dem=0;
	for( int i=0;i<na;i++)
	{
		if(a[i]==0)
		{
			b[nb++]=i;
			dem++;
		}
		
	}
	return dem;
}
void xoa( int a[], int &n )
{
	for( int i=0;i<n;i++)
	{
		if( a[i]==0)
		{	
			for( int j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
			n--;
			break;
		} 
	}
			
}
int main()
{
	int a[100],b[100];
	int n, dem,nb;
	giatriN(n);
	nhap(a,n);
	printf(" \n\n mang la: "); xuat(a,n);
	dem=tach(a,n,b,nb);
	printf("\n\n so phan tu bang 0 la: %d",dem);
	if(dem!=0)
	{	
		printf("\n\n vi tri la: "); 
		xuat(b,nb);
		xoa(a,n);
		printf("\n\n mang a moi: ");
		xuat(a,n);
	}
	return 0;
	
	
	
}








