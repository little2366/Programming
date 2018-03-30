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
//�޸����򷽷������������жϵ�Ƕ��
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
    //��map�����е�ѧУ������vector ranking�У�����Ϊr
    for(auto iter = people.begin(); iter != people.end(); iter++)
        ranking.push_back(r{iter->first, (int)score[iter->first], people[iter->first]});
    //��ranking��������
    sort(ranking.begin(), ranking.end(), comp);
    //cout << (int)ranking.size() << endl;
    printf("%d\n", (int)ranking.size());
    //��ʽ����
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


/*һ��ʼд����⣬ֻ�Ǿ��ô����һ��˼·���������ġ�һ����д�������Ҳ�ǶԵģ���������25�ֵ�ȴֻ��20�֣������5����Ϊ��ʱ���۵�
Ȼ�����ʲô�������԰�ʱ�临�ӶȾ�����С�����˺ü��滹�ǲ���
����map��vector���������������˺ܶࡣ���ǣ�Ϊʲô���ǳ�ʱ��
���ֻ�ܴ����������ԭ�򣬰�����scanf��cin���ĳ���scanf������printf��cout���ĳ���cout�����ڽ����
*/
