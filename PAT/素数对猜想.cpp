#include<iostream>
#include<cmath>
using namespace std;
int main(){
   int N,M,temp;
   int num[10000];
   cin>>N>>M;
   for(int i=0;i<N;++i){
    cin>>num[i];
   }
   for(int i=0;i<M;++i){
      for(int j=N-1;j>0;--j){
            temp=num[j];
            num[j]=num[j-1];
            num[j-1]=temp;
      }
   }
   for(int i=0;i<N;++i){
    if(i!=N-1)
      cout<<num[i]<<" ";
    else
      cout<<num[i];
   }
   return 0;
}
