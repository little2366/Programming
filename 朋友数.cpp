#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAX_SIZE 100000
int comp(const void *p,const void *q){
   return (*(int *)p-*(int *)q);
}
int getSum(int num){
    int sum = 0;
    while(num > 0){
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}
int main(){
    int N, num;
    cin >> N;
    int sum[MAX_SIZE], result[MAX_SIZE];
    for(int i=0; i<N; ++i){
        cin >> num;
        sum[i] = getSum(num);
    }
    qsort(sum, N, sizeof(int), comp);
    int k = 1;
    result[0] = sum[0];
    for(int i=1; i<N; ++i){
        if(sum[i] != sum[i-1]){
            result[k] = sum[i];
            k++;
        }
    }
    cout << k << endl;
    for(int i=0; i<(k-1); i++)
        cout << result[i] << ' ';
    if (k > 0)
        cout << result[k-1];
    else
        cout << endl;
}
