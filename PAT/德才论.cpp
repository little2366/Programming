#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAX_SIZE 100001
struct s {
    string number;
    int virtue;
    int ability;
    int total;
};
s stu1[MAX_SIZE], stu2[MAX_SIZE], stu3[MAX_SIZE], stu4[MAX_SIZE];
int comp(const s &a,const s &b){
    if(a.total != b.total){
        return a.total > b.total;
    }
    else if(a.virtue != b.virtue){
        return a.virtue > b.virtue;
    }
    else{
        return a.number < b.number;
    }
}
int main(){
    int n, l, h;
    scanf("%d%d%d", &n, &l, &h);
    string nu;
    int v, a;
    //s stu1[MAX_SIZE], stu2[MAX_SIZE], stu3[MAX_SIZE], stu4[MAX_SIZE];
    int e=0, f=0, g=0, k=0;
    int sum = 0;
    for(int i=0; i<n; ++i){
        cin >> nu;
        scanf("%d%d", &v, &a);
        if(v>=h && a>=h){
            stu1[e].number = nu;
            stu1[e].virtue = v;
            stu1[e].ability = a;
            stu1[e].total = v + a;
            ++e;
            ++sum;
        }
        else if(v>=h && (a>=l && a<h)){
            stu2[f].number = nu;
            stu2[f].virtue = v;
            stu2[f].ability = a;
            stu2[f].total = v + a;
            ++f;
            ++sum;
        }
        else if((v>=l && v<h) && (a>=l && a<h) && v>=a){
            stu3[g].number = nu;
            stu3[g].virtue = v;
            stu3[g].ability = a;
            stu3[g].total = v + a;
            ++g;
            ++sum;
        }
        else if(v>=l && a>=l){
            stu4[k].number = nu;
            stu4[k].virtue = v;
            stu4[k].ability = a;
            stu4[k].total = v + a;
            ++k;
            ++sum;
        }
    }
    sort(stu1, stu1+e, comp);
    sort(stu2, stu2+f, comp);
    sort(stu3, stu3+g, comp);
    sort(stu4, stu4+k, comp);
    printf("%d\n", sum);
    for(int i=0; i<e; ++i){
        cout << stu1[i].number;
        printf(" %d %d\n", stu1[i].virtue, stu1[i].ability);
    }
    for(int i=0; i<f; ++i){
        cout << stu2[i].number;
        printf(" %d %d\n", stu2[i].virtue, stu2[i].ability);
    }
    for(int i=0; i<g; ++i){
        cout << stu3[i].number;
        printf(" %d %d\n", stu3[i].virtue, stu3[i].ability);
    }
    for(int i=0; i<k; ++i){
        cout << stu4[i].number;
        printf(" %d %d\n", stu4[i].virtue, stu4[i].ability);
    }
    return 0;
}

/*
再次意识到cin和cout对时间的影响，一开始由于段错误导致0分，然后将MAX_SIZE缩小10倍，还是有段错误
函数的栈空间大小是有限制的，所以不能在函数内声明这么大的数组，解决方法是把数组放在全局空间
*/
