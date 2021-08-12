#include <stdio.h>
#include <string.h>

int main ()
{
   char str1[15];
   char str2[15];
   int ret;


   strcpy(str1, "Abfffbcdef");
   strcpy(str2, "AaCDEF");

   ret = strcmp(str1, str2);

   if(ret < 0)
   {
      printf("Chuoi str1 la ngan hon chuoi str2");
   }
   else if(ret > 0) 
   {
      printf("Chuoi str2 la ngan hon chuoi str1");
   }
   else 
   {
      printf("Chuoi str1 la bang chuoi str2");
   }
   
   return(0);
}
