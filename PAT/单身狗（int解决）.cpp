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

/*直接使用int类型的二维数组来存储数据，因为本题中ID是一个五位数，可以当数字来处理而不用字符串

最后的6分：
使用int又要特别注意题目给的条件是ID是5位，即使前面的数没有也是要用0来补齐的，所以一开始的输出方式不对，要改成05d
*/
