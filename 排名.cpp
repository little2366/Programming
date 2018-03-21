#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;
#define MAX_N 1002
#define MAX_M 20
struct stu{
    char name[22];
    int score;
}s[MAX_N];
int comp(stu a, stu b){
    if(a.score == b.score){
		if(strcmp(a.name, b.name) > 0)
			return a.name < b.name;
	}
	else
	     return a.score > b.score;
}
int main(){
    int N, M, G;
    while(1){
        scanf("%d", &N);
        if(N == 0)
            break;
        scanf("%d%d", &M, &G);
        int value[MAX_M] = {0};
        for(int i=1; i<=M; ++i)
            scanf("%d", &value[i]);
        int num, order, pass = 0;
        for(int i=0; i<N; ++i){
            scanf("%s%d", s[i].name, &num);
            s[i].score = 0;
            for(int j=0; j<num; ++j){
                scanf("%d", &order);
                s[i].score += value[order];
            }
            if(s[i].score >= G)
                pass ++;
        }
        cout << pass << endl;
        if(pass > 0){
            sort(s, s + N, comp);
            for(int i=0; i<pass; ++i)
                cout << s[i].name << " " << s[i].score << endl;
        }
    }
    return 0;
}

/*
一开始是没看清楚题目，当成绩相同时则按照准考证号升序输出，处理方法：在comp函数中先对成绩进行排序，如果成绩相同就对考号进行排序
Runtime Error：代码33行开一个num数组，大小写成了MAX_M，做出多少题数只是for循环结束的条件，只要一个变量就够了
*/
