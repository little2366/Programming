#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct yue{
    double kucun;
    double zong;
    double danjia;   //kucun��ʾÿ���±��Ŀ������zong��ʾÿ���±������ۼ�,danjia��ʾÿ���±��ĵ���
};
int comp(const void*p,const void*q){
    return ((struct yue *)p)->danjia<((struct yue *)q)->danjia;    //�Ӵ�С��������
}
int main(){
    struct yue bing[1000];
    int N,D,k,flag=0;     //N��ʾ�±�����������D��ʾ�г����������
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
    else{                            //���г�����������������ܿ����ʱ�����ڿ�治�������Դﵽӯ��
        for(int i=0;i<N;++i)
            sum+=bing[i].zong;
        printf("%.2f",sum);
    }
    return 0;
}
