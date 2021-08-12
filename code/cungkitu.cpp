
#include<stdio.h>

int main()
{
	char a[30];
	
	printf("Nhap chuoi a :");
	scanf("%s", &a);
	int i=0;
	int dem=1;
	while(a[i++] != '\0')
	{
		if(a[i]=='e'||a[i]=='u'||a[i]=='o'||a[i]=='a'||a[i]=='i')
			dem++;
	}
	printf("chuoi %s co chua : %d nguyen am", a, dem);
	return 0;
} 
