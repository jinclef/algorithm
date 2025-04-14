#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

char aeiou[] = {'A', 'E', 'I', 'O', 'U'};

int getIdx(char a){
    if (a == 'A') return 0;
    else if (a == 'E') return 1;
    else if (a == 'I') return 2;
    else if (a == 'O') return 3;
    else if (a == 'U') return 4;
}

int solution(string word) {
    int answer = 0;
    int idx = word.length() - 1;
    
    string compareStr = "";
    int cnt = 0;
    int charIdx = 0;
    while(compareStr != word){
        // if(cnt < 100) cout << compareStr << '\n';
        cnt++;
        if(compareStr.length() < 5) compareStr += (aeiou[charIdx]);
        else {
            // 꽉 찼으니 빼준다.
            char now = compareStr[compareStr.length() - 1];
            if(getIdx(now) == 4) { // U 빼기
                while(compareStr[compareStr.length()-1] == 'U') {
                    compareStr = compareStr.substr(0, compareStr.length()-1);
                    now = compareStr[compareStr.length() - 1];
                }
            }
            compareStr = compareStr.substr(0, compareStr.length()-1);
            compareStr += aeiou[getIdx(now) + 1];
        }
    }
    
    answer = cnt;
    return answer;
}