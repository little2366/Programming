#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX_SIZE 505
int getDigit(int color){
    int d = 0;
    if(color == 0)
        return 1;
    while(color != 0){
        color /= 10;
        ++d;
    }
    return d;
}
int main(){
    int m, n, a, b, r, num;
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &r);
    int color[MAX_SIZE][MAX_SIZE];
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            scanf("%d", &color[i][j]);
            if(color[i][j]>=a && color[i][j]<=b)
                color[i][j] = r;
        }
    }
    /*for(int i=0; i<m; ++i){
        for(int j=0; j<n-1; ++j){
            if((getDigit(color[i][j])) == 1)
                cout << "00" << color[i][j] << " ";
            else if((getDigit(color[i][j])) == 2)
                cout << "0" << color[i][j] << " ";
            else if((getDigit(color[i][j])) == 3)
                cout << color[i][j] << " ";
        }
        if((getDigit(color[i][n-1])) == 1)
            cout << "00" << color[i][n-1] << endl;
        else if((getDigit(color[i][n-1])) == 2)
            cout << "0" << color[i][n-1] << endl;
        else if((getDigit(color[i][n-1])) == 3)
            cout << color[i][n-1] << endl;
    }*/
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                printf("%03d",color[i][j]);
            }else{
                printf(" %03d",color[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
