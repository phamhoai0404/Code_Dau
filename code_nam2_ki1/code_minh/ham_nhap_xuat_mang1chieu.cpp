void nhapN( int &n)
{
	cout<<" nhap N : ";
	cin>>n;
}
void nhap( int a[], int  n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]=";
		cin>>a[i];
	}
}
void xuat( int a[], int n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];	
	}
}
