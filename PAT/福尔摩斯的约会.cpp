#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main(){
   int i,j,k,l;
   int num1,num2,num3;
   string str1,str2,str3,str4;
   char ch[2];
   cin>>str1>>str2>>str3>>str4;
   string::size_type size1=str1.size();
   string::size_type size2=str2.size();
   string::size_type size3=str3.size();
   string::size_type size4=str4.size();
   int size5=(size1>size2)?size2:size1;
   int size6=(size3>size4)?size4:size3;
   for(i=0;i<size5;++i){
        if((str1[i]==str2[i])&&(str1[i]>='A'&&str1[i]<='G')){       /*!str1的取值范围是A到G*/
            ch[0]=str1[i];             //第1对相同的大写英文字母
            k=i;
            break;
        }
   }
   for(i=k+1;i<size5;++i){
        if((str1[i]==str2[i])&&((str1[i]>='A'&&str1[i]<='N')||(str1[i]>='0'&&str1[i]<='9'))){
            ch[1]=str1[i];             //第2对相同的字符,这里的字符是否就是大写字母或是数字
            break;
        }
   }
   for(j=0;j<size6;++j){
        if((str3[j]==str4[j])&&((str3[j]>='a'&&str3[j]<='z')||(str3[j]>='A'&&str3[j]<='Z'))){
            num3=j;                    //第1对相同的英文字母出现的位置（大写或小写）
            break;
        }
   }
   num1=ch[0]-'A'+1;
   if(num1==1)
    cout<<"MON ";
   if(num1==2)
    cout<<"TUE ";
   if(num1==3)
    cout<<"WED ";
   if(num1==4)
    cout<<"THU ";
   if(num1==5)
    cout<<"FRI ";
   if(num1==6)
    cout<<"SAT ";
   if(num1==7)
    cout<<"SUN ";             //判断是星期几
   if(ch[1]>='0'&&ch[1]<='9'){
     num2=ch[1]-'0';
     cout<<"0"<<num2<<":";
   }
   else{
    num2=ch[1]-'A'+10;
    cout<<num2<<":";
   }                          //判断小时
   if(num3>=0&&num3<=9)
     cout<<"0"<<num3<<endl;
   else
    cout<<num3<<endl;         //判断分钟
   return 0;
}
