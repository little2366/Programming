#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
#define MAX_SIZE 10010
struct node {
    string name;
    int num;
};
int main(){
    int n;
    cin >> n;
    node people[MAX_SIZE];
    int sum = 0, average;
    for(int i=0; i<n; ++i){
        cin >> people[i].name >> people[i].num;
        sum += people[i].num;
    }
    average = sum / n / 2;
    int min = abs(people[0].num - average);
    string winner = people[0].name;
    for(int i=1; i<n; ++i){
        int k = abs(people[i].num - average);
        if(k < min){
            winner = people[i].name;
            min = k;
        }
    }
    cout << average << " " << winner;
    return 0;
}
