#include<stdio.h>
#include<string.h>
#define se "., "
int main()
{
	char s[]="thu strtok: 9,123.45";
	char *p;
	p=strtok(s,se);
	while(p!=NULL)
	{
		printf("%s\n",p);
		p=strtok(NULL,se);
	}
	return 0;
}


