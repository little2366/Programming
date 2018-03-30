#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#include<vector>
#include<map>
using namespace std;
struct r{
    string name;
    int score, people;
};
//修改排序方法，减少条件判断的嵌套
int comp(r a, r b){
    if(a.score != b.score ){
        return a.score > b.score ;
    }
    else if(a.people != b.people){
        return a.people < b.people ;
    }
    else{
        return a.name < b.name;
    }
}
int main(){
    int N;
    scanf("%d", &N);
    map <string, double> score;
    map <string, int> people;
    double s;
    string id, school;
    for(int i=0; i<N; ++i){
        cin >> id;
        scanf("%lf", &s);
        cin >> school;
        if(id[0] == 'B')
            s /= 1.5;
        else if(id[0] == 'T')
            s *= 1.5;
        for(int j=0; j<school.length(); ++j)
            school[j] = tolower(school[j]);
        score[school] += s;
        people[school] ++;
    }
    vector<r> ranking;
    //map<string, int>::iterator iter;
    //将map中所有的学校保存在vector ranking中，类型为r
    for(auto iter = people.begin(); iter != people.end(); iter++)
        ranking.push_back(r{iter->first, (int)score[iter->first], people[iter->first]});
    //对ranking进行排序
    sort(ranking.begin(), ranking.end(), comp);
    //cout << (int)ranking.size() << endl;
    printf("%d\n", (int)ranking.size());
    //方式二：
    int r = 1;
    printf("%d ",r);
    cout << ranking[0].name;
    printf(" %d %d\n", ranking[0].score, ranking[0].people);
    for(int i=1; i<ranking.size(); i++){
        if(ranking[i].score != ranking[i-1].score)
            r=i+1;
        printf("%d ", r);
        cout << ranking[i].name;
        printf(" %d %d\n", ranking[i].score, ranking[i].people);
    }
    return 0;
}


/*一开始写这个题，只是觉得代码多一点思路还是清晰的。一步步写下来结果也是对的，但是满分25分的却只有20分，另外的5分因为超时被扣掉
然后就想什么方法可以把时间复杂度尽量变小，改了好几版还是不行
用了map和vector，处理起来方便了很多。可是，为什么还是超时啊
最后只能从输入输出找原因，把能用scanf的cin都改成了scanf，能用printf的cout都改成了cout，终于解决了
*/
