#include "stdio.h""
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
void tongtbcnt(int n, int a[], int &d, int &t )
{
	int i;
	t=0;
	d=0;
	for (i=0;i<n;i++)
	if (ktsnt(a[i])==1)
	{
		t=t+a[i];
		d++;
	}
}
main()
{
	 int n, a[20], t,d;
	 printf("\n hay nhap so phan tu mang n =");
	 scanf("%d",&n);
	 nhapmang(n,a);
	 printf("\n mang vua nhap la :\n");	
	 xuatmang(n,a);
	 tongtbcnt(n,a,d,t);
	 if(d==0)printf("\n mang khong co so nguyen to!");
	 else{
	 	printf("\n tbc so nt la : = %f \n",1.0*t/d);
	 	}
 	
}

