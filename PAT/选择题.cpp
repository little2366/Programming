#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;
struct q{
    int no;
    int score;
    string ans;
    int error = 0;
};
int comp(const void*a,const void*b){
    return ((struct q *)a)->error<((struct q *)b)->error;    //从大到小进行排列
}
int main(){
    int n, m;
    cin >> n >> m;   //n代表学生人数，m代表多选题个数
    q que[110];
    int sel, tans;
    char a[10];
    for(int i=0; i<m; ++i){
        cin >> que[i].score;
        cin >> sel >> tans;
        que[i].no = i + 1;
        que[i].ans += (tans + '0');
        for(int j=0; j<tans; ++j){
            cin >> a[j];
            que[i].ans += ' ';
            que[i].ans += a[j];
        }
    }
    getchar();
    string s;
    int grade[1010] = {0};
    for(int i=0; i<n; ++i){
        getline(cin, s);
        int j = 0, k = 0;
        int index = 0;
        while(j < s.length()){
            if(s[j] == '(') {
                while(k++ < s.length()) {
                    if(s[k] == ')') {
                        string str = s.substr(j+1, k-j-1);
                        if(str.compare(que[index].ans) == 0)
                            grade[i] += que[index].score;
                        else
                            que[index].error ++;
                        index ++;
                        break;
                    }
                }
            }
            j++;
        }
    }
    for(int i=0; i<n; ++i)
        cout << grade[i] << endl;
    qsort(que, m, sizeof(struct q), comp);
    int max = que[0].error;
    if(max == 0)
        cout << "Too simple" << endl;
    else{
        cout << max;
        for(int i=0; i<m; ++i){
            if(que[i].error == max)
                cout << " " << que[i].no;
        }
    }
    return 0;
}
