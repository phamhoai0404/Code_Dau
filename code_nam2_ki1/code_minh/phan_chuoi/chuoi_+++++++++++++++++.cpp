#include<iostream>
#include<string.h>
using namespace std;
bool KT(char *S)
{ 
	int d=0;int n=1;
	if( S[0]==' ')n=0;    
	for(int i=1; i<strlen(S)-1; i++)    
	if (S[i] ==' ' && S[i+1] == ' ') d++;
	int z=1;
	if(S[strlen(S)-1]==' ')z=0;
    return (n==1&&d==0&&z==1);
}
int main()
{      
	char *S;
	S=new char[50]; 
	do{
		cout<<"\n nhap chuoi : ";
		gets(S);
		if(KT(S)==false)cout<<" vui long nhap lai chuoi, ";
	}while(KT(S)==false);
 	cout<<" chuoi vua nhap la: "<<S; 
 	delete(S);
	
} 
