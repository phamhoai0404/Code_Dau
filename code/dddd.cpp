#include<stdio.h>
#include<string.h>
int main()
{
	int cmp;
	char s1[] = "Ainor";
	char s2[] = "Aany";
	cmp = strcmp (s1,s2);
	if(cmp<0)printf(" %s < %s", s1,s2);
	else{
		if(cmp==0)printf("%s = %s", s1,s2);
		else printf(" %s > %s",s1,s2);	
	}
	return 0;
	
}
