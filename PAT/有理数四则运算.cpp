/*��Ŀ�����ĿӾ��ǣ����з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�������Ŀ��֤��ȷ�������û�г������ͷ�Χ��������
  ���Ⲣ�������м����õ���Ҳ�������η�Χ�ڣ��ñ�̬����ס��Ŀһ��Ҫ�������*/
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
typedef struct {
    long long int fenzi;
    long long int fenmu;
}FENSHU;
long long int gcd(long long int m,long long int n){
    if(m<n){
       long long int tmp = m;
       m = n;
       n = tmp;
    }
    if(n==0)
       return m;
    while(n>0){
       long long int tmp=m%n;
       m=n;
       n=tmp;
    }
    return m;
}
FENSHU makeFenshu(long long int a,long long int b){
   FENSHU temp;
   temp.fenzi=a;
   temp.fenmu=b;
   return temp;
}
void printFenshu(FENSHU c){
   if(c.fenmu<0){
    c.fenzi=-c.fenzi;
    c.fenmu=-c.fenmu;
   }
   long long int m,n;
   m=c.fenzi/c.fenmu;      //m��ʾ������
   n=c.fenzi-m*c.fenmu;    //n��ʾ�������ֵķ���
   long long int g=gcd(fabs(n),c.fenmu);
   n/=g;
   c.fenmu/=g;
   if(m==0&&n>0)
     cout<<n<<"/"<<c.fenmu;
   if(m==0&&n==0)
     cout<<"0";
   if(m==0&&n<0)
     cout<<"("<<n<<"/"<<c.fenmu<<")";
   if(m>0&&n>0)
     cout<<m<<" "<<n<<"/"<<c.fenmu;
   if(m>0&&n==0)
     cout<<m;
   if(m<0&&n==0)
     cout<<"("<<m<<")";
   if(m<0&&n<0)
     cout<<"("<<m<<" "<<fabs(n)<<"/"<<c.fenmu<<")";
}
FENSHU addFenshu(FENSHU a,FENSHU b){
   FENSHU temp;
   temp.fenzi=a.fenzi*b.fenmu+b.fenzi*a.fenmu;
   temp.fenmu=a.fenmu*b.fenmu;
   return temp;
}
FENSHU subFenshu(FENSHU a,FENSHU b){
   FENSHU temp;
   temp.fenzi=a.fenzi*b.fenmu-b.fenzi*a.fenmu;
   temp.fenmu=a.fenmu*b.fenmu;
   return temp;
}
FENSHU mulFenshu(FENSHU a,FENSHU b){
   FENSHU temp;
   temp.fenzi=a.fenzi*b.fenzi;
   temp.fenmu=a.fenmu*b.fenmu;
   return temp;
}
FENSHU divFenshu(FENSHU a,FENSHU b){
   FENSHU temp;
   temp.fenzi=a.fenzi*b.fenmu;
   temp.fenmu=a.fenmu*b.fenzi;
   return temp;
}
int main(){
   int a1,b1,a2,b2;
   scanf("%lld/%lld%lld/%lld",&a1,&b1,&a2,&b2);
   FENSHU a,b,c;
   a=makeFenshu(a1,b1);
   b=makeFenshu(a2,b2);
   printFenshu(a);
   cout<<" + ";
   printFenshu(b);
   cout<<" = ";
   c=addFenshu(a,b);
   printFenshu(c);
   cout<<endl;
   printFenshu(a);
   cout<<" - ";
   printFenshu(b);
   cout<<" = ";
   c=subFenshu(a,b);
   printFenshu(c);
   cout<<endl;
   printFenshu(a);
   cout<<" * ";
   printFenshu(b);
   cout<<" = ";
   c=mulFenshu(a,b);
   printFenshu(c);
   cout<<endl;
   printFenshu(a);
   cout<<" / ";
   printFenshu(b);
   cout<<" = ";
   if(b.fenzi==0)
    cout<<"Inf";
   else{
    c=divFenshu(a,b);
    printFenshu(c);
   }
   cout<<endl;
   return 0;
}
