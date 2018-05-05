#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int comp(const void*p,const void*q){
   return (*(int *)p-*(int *)q);
}
int main(){
   int N;
   cin>>N;
   int sum1=0,sum2=0,sum3=0,sum4=0;
   int num[100000];
   for(int i=0;i<N;++i){
    cin>>num[i];
   }
   qsort(num,N,sizeof(int),comp);
   if(N%2!=0){
    cout<<"1 ";
    for(int j=0;j<N/2-1;++j)
     sum1+=num[j];
    for(int k=N/2-1;k<N;++k)
     sum2+=num[k];
    int a=fabs(sum2-sum1);
    for(int j=0;j<N/2;++j)
     sum3+=num[j];
    for(int k=N/2;k<N;++k)
     sum4+=num[k];
    int b=fabs(sum3-sum4);
    cout<<(a<b?a:b);
   }
   else{
    cout<<"0 ";
    for(int j=0;j<N/2;++j)
     sum1+=num[j];
    for(int k=N/2;k<N;++k)
     sum2+=num[k];
    cout<<fabs(sum1-sum2);
   }
   return 0;
}
