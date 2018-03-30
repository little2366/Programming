#include<stdio.h>
#include<string.h>
int main(){
   char str[100000];
   int num1[100000]={0},num2[100000]={0},num3[100000]={0};
   int a=0,b=0,c=0;
   int i,j,k;
   int length;
   long long int count=0;
   gets(str);
   length=strlen(str);
   for(i=0;i<length;++i){
    if(str[i]=='P'){
        num1[a]=i;
        ++a;
    }
    if(str[i]=='A'){
        num2[b]=i;
        ++b;
    }
    if(str[i]=='T'){
        num3[c]=i;
        ++c;
    }
   }
   for(i=0;i<a;++i){
    for(j=0;j<b;++j){
        if(num1[i]<num2[j]){
          for(k=0;k<c;++k){
            if(num2[j]<num3[k])
                count++;
          }
        }
     }
   }
   printf("%d",count%1000000007);
   return 0;
}
