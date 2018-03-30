#include<iostream>
using namespace std;
#define MAX_SIZE 10000
int main(){
    int N;
    int num[MAX_SIZE], differ[MAX_SIZE], count[MAX_SIZE]={0};
    cin >> N;
    for(int i=0; i<N; ++i){
        cin>>num[i];
        int max = num[i]>=(i+1) ? num[i] : (i+1);
        int min = num[i]<(i+1) ? num[i] : (i+1);
        differ[i] = max - min;
    }
    for(int i=0; i<N; ++i)
        count[differ[i]]++;
    for(int i=N-1; i>=0; --i){
        if(count[i] > 1)
            cout << i << " " <<count[i]<<endl;
    }
}
