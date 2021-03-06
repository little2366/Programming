#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int isPalindrome(string str){
    string s = str;
    reverse(s.begin(),s.end());
    if(s == str)
        return 1;
    else
        return 0;
}
string getSum(string a, string b){
    int aLength = a.length();
    int bLength = b.length();
    int minLength = aLength<bLength ? aLength : bLength;
    int maxLength = aLength>bLength ? aLength : bLength;
    int n = 0;
    string result = "";
    for(int i=0; i<minLength; ++i){
        int c = 0, m = 0;
        c = (a[aLength-i-1] - '0') + (b[bLength-i-1] - '0') + n;
        n = c / 10;
        m = c % 10;
        result += m + '0';
    }
    for(int i=minLength; i<maxLength; ++i){
        int c = 0, m = 0;
        if(minLength == aLength)
            c = (b[bLength-i-1] - '0') + n;
        else
            c = (a[aLength-i-1] - '0') + n;
        n = c / 10;
        m = c % 10;
        result += m + '0';
    }
    if(n == 1)
        result += n + '0';
    reverse(result.begin(),result.end());
    return result;
}
int main(){
    string str;
    getline(cin, str);
    int c = 0;
    while(!isPalindrome(str)){
        string s = str;
        reverse(s.begin(),s.end());
        string t = getSum(s, str);
        cout << str << " + " << s << " = " << t << endl;
        str = t;
        c++;
        if(c >= 10){
            cout << "Not found in 10 iterations." << endl;
            break;
        }
    }
    if(c < 10){
        cout << str << " is a palindromic number." << endl;
    }
}
