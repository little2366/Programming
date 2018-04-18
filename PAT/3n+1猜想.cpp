#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int comp(const void *p,const void *q){
   return (*(int *)q-*(int *)p);
}
int main(){
   int n,num[10000],num1[10000],num2[10000],k=0;
   cin>>n;
   for(int i=0;i<n;++i){
    cin>>num[i];
    num1[i]=num[i];
   }
   for(int i=0;i<n;++i){
     while(num[i]!=1){
        if(num[i]%2==0){
           num[i]/=2;
           for(int j=0;j<n;++j){
             if(num[i]==num1[j])
                num1[j]=-1;
           }
        }
        else{
           num[i]=(num[i]*3+1)/2;
           for(int j=0;j<n;++j){
             if(num[i]==num1[j])
                num1[j]=-1;
           }
        }
      }
   }
   for(int i=0;i<n;++i){
    if(num1[i]!=-1){
        num2[k]=num1[i];
        ++k;
    }
   }
   qsort(num2,k,sizeof(int),comp);
   for(int i=0;i<k;++i){
    if(i!=k-1)
      cout<<num2[i]<<" ";
    else
      cout<<num2[i];
   }
   return 0;
}
