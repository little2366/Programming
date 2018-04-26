#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
using namespace std;
int comp(string a, string b){
    return a.compare(b) < 0;
}
int main(){
    int n, m;
    scanf("%d", &n);
    map<string, string> mp;
    for(int i=0; i<n; i++){
        string c1, c2;
        cin >> c1 >> c2;
        mp.insert(make_pair(c1, c2));
        mp.insert(make_pair(c2, c1));
    }
    scanf("%d", &m);
    string guest[10000];
    for(int i=0; i<m; ++i)
        cin >> guest[i];
    int f = 0;
    string single[10000];
    for(int i=0; i<m; ++i){
        int flag = 0;
        map<string,string>::iterator key = mp.find(guest[i]);
        if(key != mp.end()){
            for(int j=0; j<m; ++j){
                if(guest[j] == key->second){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0){
            single[f] = guest[i];
            ++f;
        }
    }
    printf("%d\n", f);
    sort(single, single+f, comp);
    for(int i=0; i<f-1; ++i)
        printf("%s ", single[i].c_str());
        printf("%s", single[f-1].c_str());
    return 0;
}
