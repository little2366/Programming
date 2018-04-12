#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX_SIZE 100
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int score[MAX_SIZE], answer[MAX_SIZE], grade[MAX_SIZE] = {0};
    for(int i=0; i<m; ++i)
        scanf("%d", &score[i]);
    for(int i=0; i<m; ++i)
        scanf("%d", &answer[i]);
    int num;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%d", &num);
            if(num == answer[j])
                grade[i] += score[j];
        }
    }
    for(int i=0; i<n; ++i)
        printf("%d\n", grade[i]);
}
