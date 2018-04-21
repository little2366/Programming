/*主要是反斜杠的问题*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAX_SIZE 1000
int main(){
    string hand, eye, mouth;
    getline(cin, hand);
    getline(cin, eye);
    getline(cin, mouth);
    string h[MAX_SIZE] = "";
    int i= 0, k = 0;
    int flag = 0;
    while(i < hand.length()){
        if(hand[i] == '['){
            flag = 1;
            ++k;
            ++i;
            continue;
        }
        else if(hand[i] == ']')
            flag = 0;
        if(flag == 1)
            h[k] += hand[i];
        ++i;
    }
    int hLength = k;
    string e[MAX_SIZE] = "";
    i= 0, k = 0;
    flag = 0;
    while(i < eye.length()){
        if(eye[i] == '['){
            flag = 1;
            ++k;
            ++i;
            continue;
        }
        else if(eye[i] == ']')
            flag = 0;
        if(flag == 1)
            e[k] += eye[i];
        ++i;
    }
    int eLength = k;
    string m[MAX_SIZE] = "";
    i= 0, k = 0;
    flag = 0;
    while(i < mouth.length()){
        if(mouth[i] == '['){
            flag = 1;
            ++k;
            ++i;
            continue;
        }
        else if(mouth[i] == ']')
            flag = 0;
        if(flag == 1)
            m[k] += mouth[i];
        ++i;
    }
    int mLength = k;
    int n;
    cin >> n;
    int lh[MAX_SIZE], le[MAX_SIZE], lrm[MAX_SIZE], re[MAX_SIZE], rh[MAX_SIZE];
    for(int i=0; i<n; ++i)
        cin >> lh[i] >> le[i] >> lrm[i] >> re[i] >> rh[i];
    for(int i=0; i<n; ++i){
        if((lh[i]<1 || lh[i]>hLength) || (le[i]<1 || le[i]>eLength) || (lrm[i]<1 || lrm[i]>mLength) || (re[i]<1 || re[i]>eLength) || (rh[i]<1 || rh[i]>hLength))
            cout << "Are you kidding me? @\\/@" << endl;
        else
            cout << h[lh[i]] << "(" << e[le[i]] << m[lrm[i]] << e[re[i]] << ")" << h[rh[i]] << endl;
    }
    return 0;
}
