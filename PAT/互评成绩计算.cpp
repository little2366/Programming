#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX_SIZE 110
int main(){
    int N, M;
    cin >> N >> M;
    int G2, stu[MAX_SIZE];
    double score[MAX_SIZE];
    for(int i=0; i<N; ++i){
        cin >> G2;
        int max = 0;
        int min = M;
        double sum = 0;
        int c = 0;
        for(int j=0; j<N-1; ++j){
            cin >> stu[j];
            if(stu[j]>=0 && stu[j]<=M){
                sum += stu[j];
                c ++ ;
                if(stu[j] >= max)
                    max = stu[j];
                if(stu[j] <= min)
                    min = stu[j];
            }
        }
        sum -= max;
        sum -= min;
        double G1 = sum / (c-2);
        score[i] = (G1 + G2) / 2;

    }
    for(int i=0; i<N; ++i)
        cout<<(int)(score[i]+0.5)<<endl;
    return 0;
}
