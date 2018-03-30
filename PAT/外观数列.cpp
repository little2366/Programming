#include<iostream>
using namespace std;
int main(){
    int d, N;
    string str = "";
    cin >> d >> N;
    str += (d + '0');
    for(int i=1; i<N; ++i){
        int length = str.length();
        string temp = "";
        int count = 1;
        for(int j=0; j<length; ++j){
            if(str[j] != str[j+1]){
                temp += str[j];
                temp += (count + '0');
                count = 1;
            }
            else{
                count ++;
            }
        }
        str = temp;
    }
    cout << str;
}
