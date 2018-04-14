#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    string radix, a, b;
    getline(cin, radix);
    getline(cin, a);
    getline(cin, b);
    int aLength = a.length();
    int bLength = b.length();
    if(aLength==1 && bLength==1 && a[0]=='0' && b[0]=='0'){
        cout << "0";
    }
    else{
        int minLength = aLength<bLength ? aLength : bLength;
        int maxLength = aLength>bLength ? aLength : bLength;
        int n = 0;
        string result = "";
        for(int i=0; i<minLength; ++i){
            int c = 0, m = 0;
            c = (a[aLength-i-1] - '0') + (b[bLength-i-1] - '0') + n;
            int r = radix[radix.length()-i-1] - '0';
            if(r == 0)
                r = 10;
            n = c / r;
            m = c % r;
            result += m + '0';
        }
        for(int i=minLength; i<maxLength; ++i){
            int c = 0, m = 0;
            if(minLength == aLength)
                c = (b[bLength-i-1] - '0') + n;
            else
                c = (a[aLength-i-1] - '0') + n;
            int r = radix[radix.length()-i-1] - '0';
            if(r == 0)
                r = 10;
            n = c / r;
            m = c % r;
            result += m + '0';
        }
        //进位大于0的情况
        /*int index = maxLength;
        while(n != 0){
            int c = n, m;
            int r = radix[radix.length()-index-1] - '0';
            if(r == 0)
                r = 10;
            n = c / r;
            m = c % r;
            result += m + '0';
            ++ index;
        }*/
        if(n != 0){
            result += n + '0';
        }
        reverse(result.begin(), result.end());
        int flag = 0;
        for(int i=0; i<result.length(); ++i){
            if(result[i]!='0'){
                flag = 1;
                cout << result[i];
            }
            else if(result[i]=='0' && flag==1)
                cout << result[i];
        }
    }
    return 0;
}
