#include<iostream>
using namespace std;
int main(){
   int num[10];
   for(int i=0;i<10;++i)
    cin>>num[i];
   for(int i=1;i<10;++i){
    if(num[i]!=0){
        cout<<i;
        num[i]-=1;
        break;
    }
   }
   if(num[0]!=0){
     for(int j=0;j<num[0];++j)
        cout<<"0";
   }
   for(int i=1;i<10;++i){
    if(num[i]!=0){
        for(int j=0;j<num[i];++j)
           cout<<i;
    }
   }
   return 0;
}
