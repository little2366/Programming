#include<iostream>
using namespace std;
int main(){
    int pa, pb;
    cin >> pa >> pb;   //两人得到的观众投票
    int i, ia=0, ib=0;
    for(int j=0; j<3; ++j){
        cin >> i;
        if(i == 0)
            ia ++;
        else if(i == 1)
            ib ++;
    }
    char winner = 'c';
    if(pa > pb){
        if(ia >= 1)
            winner = 'a';
        else
            winner = 'b';
    }
    else{
        if(ia == 3)
            winner = 'a';
        else
            winner = 'b';
    }
    cout << "The winner is " << winner << ": ";
    if(winner == 'a')
        cout << pa << " + " << ia;
    else
        cout << pb << " + " << ib;
    return 0;
}
