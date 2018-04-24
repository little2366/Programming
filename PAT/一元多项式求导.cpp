#include<iostream>
using namespace std;
int main(){
   int num[2000],j[2000];
   int n,k=0;
   while(cin>>n){
      num[k]=n;
      ++k;
   }
   for(int i=0;i<k;i+=2)
     j[i]=num[i]*num[i+1];
   for(int i=1;i<k;i+=2)
     j[i]=num[i]-1;
   cout<<j[0];
   if(k==2&&num[1]==0)
    cout<<" 0";
   else{
    for(int i=1;i<k;++i){
     if((i%2==0&&j[i]==0)||(j[i-1]==0))
       continue;
     cout<<" "<<j[i];                         //有些时候可以将空格放在数字前面输出，这样可以避免讨论
    }
   }
   return 0;
}
