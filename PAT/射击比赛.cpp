#include<iostream>
#include<string>
using namespace std;
#define MAX_SIZE 10000
int main(){
    int N;
    cin >> N;
    string winner, loser, id;
    int x, y;
    double max, min;
    cin >> id >> x >> y;
    winner = id;
    loser = id;
    max = x*x + y*y;
    min = x*x + y*y;
    for(int i=1; i<N; ++i){
        cin >> id >> x >> y;
        if((x*x + y*y) > max){
            max = x*x + y*y;
            loser = id;
        }
        if((x*x + y*y) < min){
            min = x*x + y*y;
            winner = id;
        }
    }
    cout << winner << " " << loser;
    return 0;
}
