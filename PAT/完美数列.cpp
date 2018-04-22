#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100010
int comp(const void *p,const void *q){
   return (*(long long int *)p-*(long long int *)q);
}
int main(){
    long long m, p;
    long long num[MAX_SIZE];
    cin >> m >> p;
    for(int i=0; i<m; ++i){
        cin >> num[i];
    }
    qsort(num, m, sizeof(int), comp);
    int max = 1;
    for(int i=0; i<m; ++i){
        for(int j=i+max; j<m; ++j){
            if(num[j] <= num[i] * p){
                if((j - i + 1) > max)
                    max = j - i + 1;
            }
            else
                break;
        }
    }
    cout << max << endl;
    return 0;
}

/*应该是怕了超时，超时比代码出现漏洞还要可怕。但是没想到这道题两个for循环里再套两个if也是可以的，
  关键是第二个for循环这里j是从i+max开始的，然后if不成立要及时break
*/
