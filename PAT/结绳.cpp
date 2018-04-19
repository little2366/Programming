#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define MAX_SIZE 10000
int comp(const void *p,const void *q){
   return (*(int *)p-*(int *)q);
}
int main(){
    int n;
    int length[MAX_SIZE];
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> length[i];
    qsort(length, n, sizeof(int), comp);
    double sum = ((double)length[0] / 2) + ((double)length[1] / 2);
    for(int i=2; i<n; ++i){
        sum = sum / 2 + ((double)length[i] / 2);
        //cout << sum << endl;
    }
    cout << floor(sum);
    return 0;
}
