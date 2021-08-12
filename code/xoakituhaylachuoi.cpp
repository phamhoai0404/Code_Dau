#include<stdio.h>
#include<string.h>
void xoakitu( char str[100], int vt)
{
	int n=strlen(str);
	for( int i= vt; i<n ;i++)
	{
		str[i]=str[i+1];
	}
}
void xoakhoangdau( char str[100])
{
	int k=0;
	while(str[k]==32)
	{
		xoakitu(str,k);
	}
	
}
void xoagiua(char str[100])
{
	int n=strlen(str);
	for( int i=0; i<n;i++)
	{
		if( str[i]==32)
		{
			if(str[i+1]==32)
			{
				int k=i;
				while(str[i]==32)
				{
					xoakitu(str,i);
					i=k+1;
				}
			}
		}
		
	}
}
void xoacuoi( char str[100])
{
	int k=strlen(str)-1;
	while(str[k]==32)
	{
		xoakitu(str,k);
		k=strlen(str)-1;
	}
}
int main()
{
	char str[100];
	printf(" nhap vao chuoi ki tu: ");gets( str);
	xoakhoangdau(str);
	xoagiua(str);
	xoacuoi(str);
	printf(" chuoi sau khi chuan hoa: %s",str);
	return 0;
}

















































