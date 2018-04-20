#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    int sum = 0;
    int zero = 0, one = 0;
    for(int i=0; i<str.length(); ++i){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            str[i] = tolower(str[i]);
            sum = sum + (str[i] - 'a') + 1;
        }
    }
    while(sum >= 1){
        if(sum % 2 == 0)
            zero ++;
        else if(sum % 2 == 1)
            one ++;
        sum /= 2;
    }
    cout << zero << " " << one;
    return 0;
}
