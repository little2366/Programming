#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
#define MAX_SIZE 100000
int comp(const void *p,const void *q){
   return (*(int *)p-*(int *)q);
}
int main(){
    int N;
    scanf("%d", &N);
    int num[MAX_SIZE], temp[MAX_SIZE], result[MAX_SIZE], c = 0;
    for(int i=0; i<N; ++i){
        scanf("%d", &num[i]);
        temp[i] = num[i];
    }
    qsort(temp, N, sizeof(int), comp);
    int nowMax = num[0];
    for(int i=0; i<N; ++i){
        if(num[i] >= nowMax)
            nowMax = num[i];
        if(num[i] == temp[i] && num[i] == nowMax){
            result[c] = num[i];
            c ++;
        }
    }
    printf("%d\n", c);
    for(int i=0; i<(c-1); i++)
        cout << result[i] << ' ';
    if (c > 0)
        cout << result[c-1];
    else
        cout << endl;
}

/*https://www.patest.cn/contests/pat-b-practise/1045
  直接左边和右边判断一下，结果是运行超时
  后来想了想就可以了满足第几大就排第几位条件，似乎很有道理
  错误样例：6 5 1 4 2 3
  关键条件是满足到第几位的时候这一位上的数是当前最大的
  最后就是格式的问题，当没有主元个数为0时，第二行还得换个行，666666啊
*/
