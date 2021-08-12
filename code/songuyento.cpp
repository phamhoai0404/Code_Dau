#include<stdio.h>
#include<math.h>
void nhap( int a[],int &n)
{
	printf("nhap N: ");scanf("%d",&n);
	for( int i=0;i<n;i++)
	{
		printf("a[%d]=  ",i);
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
void tach( int a[],int na)
{
	int max=0;
	for (int i=0;i<na;i++)
	{
		if(LaSNT(a[i])==1&&max<a[i])max=a[i];	
	}
	if(max==0)printf("\n\n khong co so nguyen to! ");
	else printf(" \n\n nguyen to max la: %d",max);
}
void maxnt(int a[], int n)
{
	int i, maxnt;
	for(i=0;i<n;i++)
	if(LaSNT(a[i])==1)maxnt=a[i];
	if(LaSNT(a[i])==1&&maxnt<a[i])maxnt=a[i];
	printf("\n max nguyen to la: %d", maxnt);
}
int main()
{
	int a[50]; int b[50];
	int x,y;
	nhap(a,x);
	printf("\n\n mang a la:");
	xuat(a,x);
	tach(a,x);
	return 0;
	
}


