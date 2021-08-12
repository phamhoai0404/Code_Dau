#include<stdio.h>
#include<math.h>

void nhap( float a[],int n)
{
	for( int i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%f",&a[i]);
		
	}
}

void xuat( float a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%10.2f",a[i]);
		
	}
}
float timmax( float a[], int n)
{
	int max=a[0];
	for( int i=1;i<n;i++)
	{
		if(max<a[i])max=a[i];
		
	}
	return max;
	
}
void vitri(float a[], int na,float x,  float b[], int &nb )
{
	nb=0;
	for( int i=0;i<na;i++)
	{
		if( a[i]==x)
		{
			b[nb++]=i;
			a[i]=-1;
		}
	}
}
int main()
{
	float a[100],b[100];
	int na,nb;
	do{
		printf(" nhap n:");scanf("%d",&na);
	}while(!(na>0&&na<15));
	nhap(a,na);
	printf("mang la: ");
	xuat(a,na);
	printf(" \n\n max la: %.2f", timmax(a,na));
	vitri(a,na,timmax(a,na),b,nb);
	printf(" \n\n cac vitri max: ");
	xuat(b,nb);
	printf(" \n\n mang a moi la: ");
	xuat(a,na);
	return 0;
}






