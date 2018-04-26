#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
using namespace std;
int comp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int n, m;
    scanf("%d", &n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        mp.insert(make_pair(c1, c2));
        mp.insert(make_pair(c2, c1));
    }
    scanf("%d", &m);
    int guest[10010];
    for(int i=0; i<m; ++i)
        scanf("%d", &guest[i]);
    int f = 0;
    int single[10010];
    for(int i=0; i<m; ++i){
        int flag = 0;
        map<int, int>::iterator key = mp.find(guest[i]);
        if(key != mp.end()){
            for(int j=0; j<m; ++j){
                if(guest[j] == key->second){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0){
            single[f] = guest[i];
            ++f;
        }
    }
    printf("%d\n", f);
    qsort(single, f, sizeof(int),comp);
    /*for(int i=0; i<f-1; ++i)
        printf("%d ",single[i]);
    printf("%d",single[f-1]);*/
    for(int i=0; i<f; ++i){
        if(!i)
            printf("%05d",single[i]);
        else
            printf(" %05d",single[i]);
    }
    return 0;
}

/*ֱ��ʹ��int���͵Ķ�ά�������洢���ݣ���Ϊ������ID��һ����λ�������Ե�����������������ַ���

����6�֣�
ʹ��int��Ҫ�ر�ע����Ŀ����������ID��5λ����ʹǰ�����û��Ҳ��Ҫ��0������ģ�����һ��ʼ�������ʽ���ԣ�Ҫ�ĳ�05d
*/
