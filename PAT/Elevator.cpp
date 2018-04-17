#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    int num[1000];
    int floor,time=0;
    cin>>n;
    for(int i=1;i<=n;++i)
       cin>>num[i];
    num[0]=0;
    for(int i=1;i<=n;++i){
        floor=num[i]-num[i-1];
        if(floor>0)
            time+=(6*floor);
        else
            time+=(4*fabs(floor));
        time+=5;
    }
    cout<<time;
    return 0;
}
