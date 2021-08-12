#include<iostream>
#include<math.h>
using namespace std;
void nhap( float &x, int &n)
{
	cout<<"nhap x: ";cin>>x;
	cout<<"\n nhap n: ";cin>>n;
}
float tinh( float x, int n)
{
	float s;
	if(n>=2&&x!=0)
	{
		s=0;
		float a=sqrt(abs(n*x));
		for( int i=2;i<=n;i++)
		{	
			s+=a/i;
		}
	}else s=pow(n*x,2);
	return s;
}
int main()
{
	float x; 
	int n;
	nhap(x,n);
	cout<<"\n s= "<<tinh(x,n);
	return 0;
}
			
