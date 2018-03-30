#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX_SIZE 100000
struct r{
    string name;
    double score;
    int people;
}ranking[MAX_SIZE];
int compForSchool(string a, string b){
    return a.compare(b) < 0;
}
//最初的排序方法写法
int compForRank(r a, r b){
    if(a.score == b.score){
        if(a.people == b.people){
            if(a.name.compare(b.name) != 0)
                return a.name < b.name;
        }
        else
            return a.people < b.people;
    }
    else
        return a.score > b.score;
}
int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; ++i){
        ranking[i].score = 0;
        ranking[i].people = 0;
    }
    int M = 0, score;
    string id, school;
    for(int i=0; i<N; ++i){
        cin >> id >> score >> school;
        if(id[0] == 'B')
            score /= 1.5;
        else if(id[0] == 'T')
            score *= 1.5;
        for(int j=0; j<school.length(); ++j){
            school[j] = tolower(school[j]);
        }
        int flag = 0;
        for(int j=0; j<M; ++j){
            if(school.compare(ranking[j].name) == 0){
                ranking[j].score += score;
                ranking[j].people ++;
                flag = 1;
            }
        }
        if(flag == 0){
            ranking[M].name = school;
            ranking[M].score += score;
            ranking[M].people ++;
            M ++;
        }
    }
    sort(ranking, ranking + M, compForRank);
    cout << M << endl;
    //关于排名情况相同的两种处理
    //方式一：
    int presScore = -1, rank = 0;
    for(int i=0; i<M; ++i){
        if(ranking[i].score != presScore){
            rank = i+1;
        }
        presScore = ranking[i].score;
        cout << rank;
        cout << " " << ranking[i].name << " " << ranking[i].score << " " << ranking[i].people << endl;
    }
    return 0;
}
