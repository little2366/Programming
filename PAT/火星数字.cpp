/*自己的写法，比较麻烦*/
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<sstream>
using namespace std;
int main(){
   int N;
   cin>>N;
   getchar();
   string str;
   while(N--){
    getline(cin,str);
    string::size_type size=str.size();
    if(str[0]>='0'&&str[0]<='9'){
        double num1=0;
        for(int i=0;i<size;++i)
            num1+=((str[i]-'0')*pow(10,(double)size-1-i));
        int a=num1/13;
        int b=num1-13*a;
        if(a==0&&b==0)
          cout<<"tret";
        else if(a==0&&b!=0){
         if(b==1)
          cout<<"jan";
         else if(b==2)
          cout<<"feb";
         else if(b==3)
          cout<<"mar";
         else if(b==4)
          cout<<"apr";
         else if(b==5)
          cout<<"may";
         else if(b==6)
          cout<<"jun";
         else if(b==7)
          cout<<"jly";
         else if(b==8)
          cout<<"aug";
         else if(b==9)
          cout<<"sep";
         else if(b==10)
          cout<<"oct";
         else if(b==11)
          cout<<"nov";
         else if(b==12)
          cout<<"dec";
        }
        else if(a!=0&&b!=0){
         if(a==1)
          cout<<"tam ";
         else if(a==2)
          cout<<"hel ";
         else if(a==3)
          cout<<"maa ";
         else if(a==4)
          cout<<"huh ";
         else if(a==5)
          cout<<"tou ";
         else if(a==6)
          cout<<"kes ";
         else if(a==7)
          cout<<"hei ";
         else if(a==8)
          cout<<"elo ";
         else if(a==9)
          cout<<"syy ";
         else if(a==10)
          cout<<"lok ";
         else if(a==11)
          cout<<"mer ";
         else if(a==12)
          cout<<"jou ";
         if(b==1)
          cout<<"jan";
         else if(b==2)
          cout<<"feb";
         else if(b==3)
          cout<<"mar";
         else if(b==4)
          cout<<"apr";
         else if(b==5)
          cout<<"may";
         else if(b==6)
          cout<<"jun";
         else if(b==7)
          cout<<"jly";
         else if(b==8)
          cout<<"aug";
         else if(b==9)
          cout<<"sep";
         else if(b==10)
          cout<<"oct";
         else if(b==11)
          cout<<"nov";
         else if(b==12)
          cout<<"dec";
        }
        else if(a!=0&&b==0){
         if(a==1)
          cout<<"tam";
         else if(a==2)
          cout<<"hel";
         else if(a==3)
          cout<<"maa";
         else if(a==4)
          cout<<"huh";
         else if(a==5)
          cout<<"tou";
         else if(a==6)
          cout<<"kes";
         else if(a==7)
          cout<<"hei";
         else if(a==8)
          cout<<"elo";
         else if(a==9)
          cout<<"syy";
         else if(a==10)
          cout<<"lok";
         else if(a==11)
          cout<<"mer";
         else if(a==12)
          cout<<"jou";
        }
    }
    else{
       istringstream istrm(str);
       string word;
       int num=0;
       while(istrm>>word){
        if(word=="tret")
            num+=0;
        else if(word=="jan")
            num+=1;
        else if(word=="feb")
            num+=2;
        else if(word=="mar")
            num+=3;
        else if(word=="apr")
            num+=4;
        else if(word=="may")
            num+=5;
        else if(word=="jun")
            num+=6;
        else if(word=="jly")
            num+=7;
        else if(word=="aug")
            num+=8;
        else if(word=="sep")
            num+=9;
        else if(word=="oct")
            num+=10;
        else if(word=="nov")
            num+=11;
        else if(word=="dec")
            num+=12;
        else if(word=="tam")
            num+=(13*1);
        else if(word=="hel")
            num+=(13*2);
        else if(word=="maa")
            num+=(13*3);
        else if(word=="huh")
            num+=(13*4);
        else if(word=="tou")
            num+=(13*5);
        else if(word=="kes")
            num+=(13*6);
        else if(word=="hei")
            num+=(13*7);
        else if(word=="elo")
            num+=(13*8);
        else if(word=="syy")
            num+=(13*9);
        else if(word=="lok")
            num+=(13*10);
        else if(word=="mer")
            num+=(13*11);
        else if(word=="jou")
            num+=(13*12);
       }
       cout<<num;
    }
    cout<<endl;
    }
   return 0;
}

