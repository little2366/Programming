#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    string str;
    int flag1=1,flag2=1;
    int j=0,l=0,k;
    int count=0;
    int shuzi[10000],zhishu[10000];
    cin>>str;
    string::size_type size=str.size();
    for(int i=0;i<size;++i){
        if(str[i]=='E')
            k=i;
    }
    for(int i=1;i<k;++i){
        if(str[i]>='0'&&str[i]<='9'){
          shuzi[j]=str[i]-'0';
          ++j;
        }
    }
    for(int i=0;i<j;++i){
        if(shuzi[i]==0)
            count++;
        else
            break;
    }
    for(int i=k+2;i<size;++i){
        zhishu[l]=str[i]-'0';
        ++l;
    }
    double zs=0;
    for(int i=0;i<l;++i){
        zs+=zhishu[i]*pow(10,(double)l-i-1);
    }
    if(str[0]=='-')
        flag1=0;
    if(str[k+1]=='-')
        flag2=0;
    /*先考虑正数与负数的情况*/
    if(!flag1)
      cout<<"-";
    /*指数是负数的情况*/
    if(!flag2){
      for(int i=0;i<zs-1;++i){
        if(i==0)
            cout<<"0.";
        cout<<"0";
      }
      for(int i=0;i<j;++i)
        cout<<shuzi[i];
    }
    /*指数是正数的情况*/
    else{
       if(zs+1>j){
         for(int i=count;i<j;++i)
            cout<<shuzi[i];
         for(int i=0;i<zs-j+1;++i)
            cout<<"0";
       }
       else if(zs+1==j){
         for(int i=count;i<j;++i)
            cout<<shuzi[i];
       }
       else{
        if(zs<=count){
         for(int i=zs;i<j;++i){
            if(i==zs)
                cout<<shuzi[i]<<".";
            else
                cout<<shuzi[i];
          }
        }
        else{
          for(int i=count;i<j;++i){
            if(i==zs)
                cout<<shuzi[i]<<".";
            else
                cout<<shuzi[i];
          }
        }
      }
    }
    return 0;
}
