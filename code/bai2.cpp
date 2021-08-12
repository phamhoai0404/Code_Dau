#include<stdio.h>
#include<math.h>
int giatriN( int &n)
{
	do{
		printf(" nhap N: "); scanf("%d",&n);
		if(!((n>=3)&&(n<=25)))printf(" nhap lai, ");
	}while(!((n>=3)&&(n<=25)));
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
float TBC(int x, int y )
{
	return x/y;
}
void dem( int a[], int n, int &chan, int &le, int &tongchan, int &tongle)
{
	chan=0;le=0;
	tongchan=0;tongle=0;
	for(int i=0;i<n;i++)
	{	
		if( a[i]%2==0&&a[i]<0)
		{	
			tongchan+=a[i];
			chan++;
		}
		if( a[i]%2==1&&a[i]>0)
		{
			tongle+=a[i];
			le++;
		}
			
	}
	
}
int tim( int x)
{
	int dem=0;
	for( int i=1;i<=x;i++)
	{
		if( x%i==0)dem++;	
	}
	if( dem==2)return 1;
	else return 0;
}
void SNT( int a[], int n, int &dem, int &tong)
{
	tong=0;
	dem=0;
	for( int i=0;i<n;i++)
	{
		if( tim(a[i])==1)
		{
			tong+= a[i];
			dem++;
		}
	}
	
}
int main()
{
	int a[100];
	int n,demchan,demle,tongchan,tongle, demNT, tongNT;
	giatriN(n);
	nhap(a,n);
	printf("mang la: ");
	xuat(a,n);
	dem(a,n,demchan,demle,tongchan,tongle);
	printf("\n\n  so chan am la: %d \n \n so le am la: %d",demchan, demle);
	if(demchan!=0)printf("\n\n  TBC chan am la: %.3f", TBC(tongchan,demchan));
	if( demle!=0)printf("\n\n TBC le duong la : %.3f", TBC(tongle, demle));
	SNT(a,n,demNT,tongNT);
	if( demNT!=0)printf("\n\n  TBC cac so nguyen to la: %.3f",TBC(tongNT, demNT));
	return 0;
}
















