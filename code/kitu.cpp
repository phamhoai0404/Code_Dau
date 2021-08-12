#include<stdio.h>
#include<string.h>

void dao( char s1[], char s2[])
{
	int i;
	int l=strlen(s1);
	for( i=0; i<l;i++)s2[i]=s1[(l-1)-i];
	
}
int  main()
{
	char s1[100], s2[100];
	
	printf("\n\n nhap vao chuoi ki tu: ");
	gets(s1);
	dao(s1,s2);
	printf(" ket qua sau dao nguoc: %s", s2);
	return 0;
	
	
}
