#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct yue{
    double kucun;
    double zong;
    double danjia;   //kucun表示每种月饼的库存量，zong表示每种月饼的总售价,danjia表示每种月饼的单价
};
int comp(const void*p,const void*q){
    return ((struct yue *)p)->danjia<((struct yue *)q)->danjia;    //从大到小进行排列
}
int main(){
    struct yue bing[1000];
    int N,D,k,flag=0;     //N表示月饼的种类数，D表示市场最大需求量
    double total[1000],sum=0;
    cin>>N>>D;
    for(int i=0;i<N;++i)
        cin>>bing[i].kucun;
    for(int i=0;i<N;++i)
        cin>>bing[i].zong;
    for(int i=0;i<N;++i)
        bing[i].danjia=bing[i].zong/bing[i].kucun;
    qsort(bing,N,sizeof(struct yue),comp);
    total[0]=bing[0].kucun;
    for(int i=1;i<N;++i){
        total[i]=total[i-1]+bing[i].kucun;
    }
    for(int i=0;i<N;++i){
        if(D<=total[i]){
            flag=1;
            k=i;
            break;
        }
    }
    if(flag){
      for(int i=0;i<k;++i)
        sum+=bing[i].zong;
      double yu=D-total[k-1];
      sum=sum+yu*bing[k].danjia;
      printf("%.2f",sum);
    }
    else{                            //当市场的最大需求量大于总库存量时，由于库存不够，所以达到盈利
        for(int i=0;i<N;++i)
            sum+=bing[i].zong;
        printf("%.2f",sum);
    }
    return 0;
}
