#include<iostream>
#include<iomanip>
using namespace std;
int main(){
   int num[2000],num1[2000],num2[2000],num4[2000],num5[2000];
   int n,k=0,a=0,b=0,c=0,d=0,flag=1;
   double total1=0,total2=0,total3=0,total4=0;
   cin>>n;
   for(int i=0;i<n;++i){
    cin>>num[i];
   }
   for(int i=0;i<n;++i){
     if(num[i]%5==0&&num[i]%2==0){
        num1[d]=num[i];
        ++d;
     }
     if(num[i]%5==1){
        num2[a]=num[i];
        ++a;
     }
     if(num[i]%5==2)
        total3++;
     if(num[i]%5==3){
        num4[b]=num[i];
        ++b;
     }
     if(num[i]%5==4){
        num5[c]=num[i];
        ++c;
     }
   }
   if(d==0)
    cout<<"N ";
   else{
    for(int i=0;i<d;++i)
       total1+=num1[i];
    cout<<total1<<" ";
   }                                   //�ܱ�5����������������ż���ĺ�
   if(a==0)
    cout<<"N ";
   else{
    for(int i=0,flag=1;i<a;++i,flag*=-1)
     total2+=(flag*num2[i]);
    cout<<total2<<" ";                 //��5������1�����ְ�����˳����н������
   }
   if(total3==0)
    cout<<"N ";
   else
    cout<<total3<<" ";                 //��5������2�����ָ���
   if(b==0)
    cout<<"N ";
   else{
     for(int i=0;i<b;++i)
        total4+=num4[i];
     cout<<fixed<<setprecision(1)<<total4/b<<" ";
   }                                                    //��5������3�����ֵ�ƽ����
   if(c==0)
    cout<<"N";
   else{
     int maxNumber=num5[0];
     for(int i=0;i<c;++i){
       if(num5[i]>maxNumber)
        maxNumber=num5[i];
     }
     cout<<maxNumber;
   }                                   //��5������4���������������
   return 0;
}
