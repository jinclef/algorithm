#include<string>
#include <iostream>
#include <stack>

using namespace std;

stack<char> bracket;

bool solution(string s)
{
    bool answer = true;
    
    for (int i=0; i<s.length(); i++){
        char a = s[i];
        if (a==')'){
            if (bracket.empty()){ answer = false; break; }
            else if(bracket.top() != '(') {answer = false; break;}
            else { // '('
                bracket.pop(); 
            }
        } else if (a=='('){
            bracket.push(a);
        }
    }
    if(!bracket.empty()) answer = false;
    return answer;
}
