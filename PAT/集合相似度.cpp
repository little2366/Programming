#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
#define MAX_SIZE 100
 int main(){
     set<int> s[MAX_SIZE];
     int n, m, x, k, y1, y2;
     cin >> n;
     for(int i=0; i<n; ++i){
         cin >> m;
         for(int j=0;j<m;j++){
             cin >> x;
             s[i].insert(x);
         }
    }
    cin >> k;
    for(int j=0; j<k; ++j){
         cin >> y1 >> y2;
         int same = 0;
         set<int>::iterator aa;
         for(aa=s[y1].begin(); aa!=s[y1].end(); aa++){
             if(s[y2].find(*aa) != s[y2].end())
                same++;
         }
         double ans = same * 1.0 / (s[y1].size() + s[y2].size() - same);
         printf("%.2f%%\n", ans*100);
     }
     return 0;
}

