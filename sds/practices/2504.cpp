// 괄호의 값

#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;

string brackets;
int pairs[31]; // pairs[i] = i번째 괄호의 짝 괄호 인덱스.

int findIdx(char a, int idx){
    int simcnt = 0;
    char pairA = (a=='(') ? ')' : ']';

    for (int i=idx+1; brackets.length(); i++){
        if(brackets[i] == a) simcnt++;
        if(brackets[i] == pairA) {
            if(simcnt==0) return i;
            else simcnt--;
        }
    }
    return -1;
}

stack<char> bs;
ll res;
ll temp;
int notpaired;

int main(){
    cin >> brackets;

    // find pair bracket idx
    // for (int i=0;i<brackets.length(); i++){
    //     int pairIdx = findIdx(brackets[i], i);
    //     if(pairIdx == -1) return 0;
    //     else pairs[i] = pairIdx;
    // }
    string cals = "(";
    // calculate
    for (int i=0; i<brackets.length(); i++){
        if(brackets[i] == '(' || brackets[i] == '['){
            if(i-1>=0 && (brackets[i-1] == ')' || brackets[i-1] == ']')) cals.append("+(");
            
            if(brackets[i] == '(') cals.append("2*(");
            else if(brackets[i] == '[') cals.append("3*(");
        }
        else if(brackets[i] == ')' || brackets[i] == ']'){
            if(i-1>=0 && (brackets[i-1] == ')' || brackets[i-1] == ']')) cals.append(")*");
            cals.append("1)");
        }
    }

    cout << cals <<'\n';

    return 0;
}