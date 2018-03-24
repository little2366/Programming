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
  ֱ����ߺ��ұ��ж�һ�£���������г�ʱ
  ����������Ϳ���������ڼ�����ŵڼ�λ�������ƺ����е���
  ����������6 5 1 4 2 3
  �ؼ����������㵽�ڼ�λ��ʱ����һλ�ϵ����ǵ�ǰ����
  �����Ǹ�ʽ�����⣬��û����Ԫ����Ϊ0ʱ���ڶ��л��û����У�666666��
*/
