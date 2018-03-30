#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
void forJudge(string str){
    int length = str.length();
    int shuzi=0, zimu=0, xsd=0, other=0;
    for(int i=0; i<length; ++i){
        if(str[i]>='0' && str[i]<='9')
            shuzi = 1;
        else if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
            zimu = 1;
        else if(str[i]=='.')
            xsd = 1;
        else
            other = 1;
    }
    if(length < 6)
        cout << "Your password is tai duan le." << endl;
    else{
        if(shuzi==0 && zimu==0)
            cout << "Your password is tai luan le." << endl;
        else if(shuzi==1 && zimu==0){
            if(other==1)
                cout << "Your password is tai luan le." << endl;
            else if(other==0)
                cout << "Your password needs zi mu." << endl;
        }
        else if(shuzi==0 && zimu==1){
            if(other==1)
                cout << "Your password is tai luan le." << endl;
            else if(other==0)
                cout << "Your password needs shu zi." << endl;
        }
        else if(shuzi==1 && zimu==1){
            if(other==1)
                cout << "Your password is tai luan le." << endl;
            else if(other==0)
                cout << "Your password is wan mei." << endl;
        }
    }
}
int main(){
    int N;
    cin >> N;
    getchar();
    string str;
    while(N--){
        getline(cin, str);
        forJudge(str);
    }
}
