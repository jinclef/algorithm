#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

map<string, bool> visited;
queue<pair<int, string>> singles;

// BFS로 풀어서 찾자마자 return하거나, DFS로 완전탐색 + min 값.
int bfs(string start, string target, vector<string> words){
    bool found = false;
    int level = 0;
    
    while(!singles.empty()){
        // 0. 찾으면 break;
        if(singles.front().second == target) {
            found = true;
            break;
        }
        
        // 0. 이미 앞에 레벨에서 썼던 글자면 어차피 min 보다 큰 단계임. 스킵해도 ㄱㅊ.
        if(visited[start]){
            start = singles.front().second;
            singles.pop();
            continue;
        }
        
        visited[start] = true;
        singles.pop();
        
        // 1. 한 글자만 다른 단어 찾기
        for(int i=0; i<words.size(); i++){
            int diff = 0;
            for(int j=0; j<start.length(); j++){
                if(start[j] != words[i][j]) diff++;
                if(diff>1) break;
            }
            if(diff==1 && !visited[words[i]]) {
                singles.push(make_pair(level, words[i]));
            }
        }
        
        // 2. BFS
        level = singles.front().first+1;
        start = singles.front().second;
    }
    return (found ? singles.front().first+1 : 0);
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    singles.push(make_pair(0,begin));
    answer = bfs(begin, target, words);
    return answer;
}
