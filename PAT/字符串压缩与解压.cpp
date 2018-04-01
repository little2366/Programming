#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
void compress(string str){
    int c = 0;
    for(int i=0; i<str.length()-1; ++i){
        if(str[i] == str[i+1])
            c++;
        else{
            if(c ==0)
                cout << str[i];
            else{
                cout << c+1 << str[i];
                c = 0;
            }
        }
    }
    if(c > 0)
        cout << c+1 << str[str.length()-1] << endl;
    else if(c == 0)
        cout << str[str.length()-1] << endl;
}
void decompress(string str){
    int i = 0;
    while(i<str.length()){
        if(str[i]>='0' && str[i]<='9'){
            int k = 1;
            while(1){
                if(str[i+k]>='0' && str[i+k]<='9')
                    k++;
                else
                    break;
            }
            int sum = 0;
            int m = 1;
            for(int j=i+k-1; j>=i; --j){
                sum += ((str[j]-48) * m);
                m *= 10;
            }
            for(int j=0; j<sum-1; ++j)
                cout << str[i+k];
            i+=k;
        }
        else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]==' '){
            cout << str[i];
            i+=1;
        }
    }
}
int main(){
    char ch;
    cin >> ch;
    string str;
    getchar();
    getline(cin, str);
    if(ch == 'C')
        compress(str);
    else if(ch == 'D')
        decompress(str);
    return 0;
}
