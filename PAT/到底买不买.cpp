#include<iostream>
#include<string>
using namespace std;
int main(){
   string s1,s2;
   int n1[10]={0},n2[26]={0},n3[26]={0};
   int m1[10]={0},m2[26]={0},m3[26]={0};
   int k1[10]={0},k2[26]={0},k3[26]={0};
   int total=0,sum=0;
   cin>>s1>>s2;
   string::size_type size1=s1.size();
   string::size_type size2=s2.size();
   for(int i=0;i<size1;++i){
     if(s1[i]>='0'&&s1[i]<='9')
        n1[s1[i]-'0']++;
     if(s1[i]>='a'&&s1[i]<='z')
        n2[s1[i]-'a']++;
     if(s1[i]>='A'&&s1[i]<='Z')
        n3[s1[i]-'A']++;
   }
   for(int i=0;i<size2;++i){
     if(s2[i]>='0'&&s2[i]<='9')
        m1[s2[i]-'0']++;
     if(s2[i]>='a'&&s2[i]<='z')
        m2[s2[i]-'a']++;
     if(s2[i]>='A'&&s2[i]<='Z')
        m3[s2[i]-'A']++;
   }
   for(int i=0;i<10;++i){
     k1[i]=n1[i]-m1[i];
     if(k1[i]<0)
        total+=(-k1[i]);
     sum+=k1[i];
   }
   for(int i=0;i<26;++i){
     k2[i]=n2[i]-m2[i];
     if(k2[i]<0)
        total+=(-k2[i]);
     sum+=k2[i];
   }
   for(int i=0;i<26;++i){
     k3[i]=n3[i]-m3[i];
     if(k3[i]<0)
        total+=(-k3[i]);
     sum+=k3[i];
   }
   if(total>0)
    cout<<"No "<<total;
   else
    cout<<"Yes "<<sum;
   return 0;
}
