//思路：如果有一个P出现，则只要知道后面有多少种AT可选，则这个P可以对应的PAT选择方法就有多少种；AT类似。
#include<stdio.h>
#include<string.h>
int main(){
   char str[100001]; /*长度不超过10的五次方，如果用字符数组的话，则字符串的长度至少是105+1（结束符'/0')*/
   long long int num1=0,num2=0,num3=0;
   int length;
   gets(str);
   length=strlen(str);
   while(length--){
    if(str[length]=='T')
        num3++;
    else if(str[length]=='A')
        num2+=num3;
    else
        num1+=num2;
   }
   printf("%d",num1%1000000007);
   return 0;
}
