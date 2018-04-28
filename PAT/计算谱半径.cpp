#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    double max = 0;
    int a, b;
    for(int i=0; i<n; ++i){
        scanf("%d%d", &a, &b);
        double r = sqrt(a*a + b*b);
        if(r > max)
            max = r;
    }
    printf("%.2f", max);
    return 0;
}
