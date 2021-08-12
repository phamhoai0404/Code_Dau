
int ktcp( int n)
{
	for( int i=1;i<=n/2;i++)
	{
		if(i*i==n)return 1;
	}
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
	int k=-1, max;
	for(int i=0;i<n;i++)
	{
		if(ktsnt(a[i])==1)
		{	
			max=a[i];
			k=i;
			break;
		}
	}
	if(k==-1)printf("\n mang  khong co so nguyen to nen khong phai lam tiep !");
	else{
		int x=n;
		for(int i=k+1;i<n;i++)
		{
			if(ktsnt(a[i])==1&&a[i]>max)max=a[i];
		}
		for( int i=0;i<n;i++)
		{
			if(ktcp(a[i])==1)
			{
				chen(n,a,i,max);
				break;
			}
		}
		if(n==x)printf("\n mang khong co so chinh phuong");
		
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
	 int x=n;
	 chenmang(n,a);
	 if(n!=x)
	 {
	 	printf("\n mang moi sau khi chen la: ");
	 	xuatmang(n,a);
	}
	}
	 

