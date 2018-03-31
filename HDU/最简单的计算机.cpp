#include<iostream>
#include<string>
using namespace std;
int main(){
    int m1, m2;
    while(cin >> m1 >> m2){
        string operation;
        cin >> operation;
        int r1=0, r2=0, r3=0;
        for(int i=0; i<operation.length(); ++i){
            if(operation[i] == 'A'){
                r1 = m1;
            }
            else if(operation[i] == 'B'){
                r2 = m2;
            }
            else if(operation[i] == 'C'){
                m1 = r3;
            }
            else if(operation[i] == 'D'){
                m2 = r3;
            }
            else if(operation[i] == 'E'){
                r3 = r1 + r2;
            }
            else if(operation[i] == 'F'){
                r3 = r1 - r2;
            }
        }
        cout << m1 << "," << m2 << endl;
    }
    return 0;
}
