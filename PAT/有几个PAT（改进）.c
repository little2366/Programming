//˼·�������һ��P���֣���ֻҪ֪�������ж�����AT��ѡ�������P���Զ�Ӧ��PATѡ�񷽷����ж����֣�AT���ơ�
#include<stdio.h>
#include<string.h>
int main(){
   char str[100001]; /*���Ȳ�����10����η���������ַ�����Ļ������ַ����ĳ���������105+1��������'/0')*/
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
