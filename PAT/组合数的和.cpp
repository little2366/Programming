#include<iostream>
using namespace std;
#define MAX_SIZE 20
int main(){
    int n;
    cin >> n;
    int num[MAX_SIZE];
    for(int i=0; i<n; ++i)
        cin >> num[i];
    int sum = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(i != j){
                int m = num[i] * 10 + num[j];
                sum += m;
            }
        }
    }
    cout << sum;
    return 0;
}
