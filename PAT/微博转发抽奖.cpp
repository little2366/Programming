#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
#define MAX_SIZE 1010
int main(){
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    string user[MAX_SIZE];
    for(int i=1; i<=m; ++i)
        cin >> user[i];
    int j = s;
    map<string, int> prize;
    string win[MAX_SIZE];
    int k = 0;
    while(j <= m){
        int flag = 0;
        if(prize.count(user[j]) == 0){
            prize.insert(make_pair(user[j], j));
            win[k] = user[j];
            k ++;
            flag = 1;
        }
        if(flag)
            j += n;
        else
            j ++;
    }
    if(prize.size() == 0)
        cout << "Keep going..." << endl;
    else{
        for(int i=0; i<k; ++i)
            cout << win[i] << endl;
    }
    return 0;
}
