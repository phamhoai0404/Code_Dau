#include<iostream>
#include<stdio.h>
using namespace std;
 void nhap(int a[], int &n )
 {
 	printf(" nhap n");	scanf("%d",&n);
 	for(int i=0; i<n; i++)
 	{
 		printf("a[%d]=",i);	scanf("%d",&a[i]);
	 }
 }
 
 void Xuat(int a[],int n)
 {
 	for(int i=0; i<n; i++)
 	{
 		printf(" \t %d",a[i]);
	 }
 }
 
 void Ktra(int a[],int n, int b[],int &nb, int &tong)
 {
 	int dem=1; tong=0; nb=0;
 	for(int i=1; i<n; i++)
 	{
 		for(int j=2; j<a[i]/2; j++)
 		{
 			if(a[i]%j==0)
 			{
 				dem+=j;
 				
 					if(dem==a[i])
					{
					 	b[nb]=a[i];
					 	nb++;
 						tong+=a[i];
					}
 				
				 
			 }
		 }
	 }
 }
 
 int main()
 {
 	int a[100],n,b[50],nb,tong;													
 	nhap(a,n);
 	printf("mang vua nhap la:");
 	Xuat(a,n);
 	Ktra(a,n,b,nb,tong);
 	{
 		if(tong!=0)
		 {
 			printf("\n cac so hoan hao trong mang la:");
 			Xuat(b,nb);
		 }
		 else printf("\n trong mang khong co so hoan hao");
		 return 0;
	 }
 }
