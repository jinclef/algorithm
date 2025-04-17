#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
queue<int> process;

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};

priority_queue<int> pq;
queue<pii> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(make_pair(i, priorities[i]));
    }
    
    int turn = 0;
    while(!pq.empty()){
        pii top = q.front();
        q.pop();
        
        if (pq.top() > top.second){ // 큰게 있다면 꺼내서 뒤로 보낸다
            q.push(top);
            continue;
        } else{
            turn++;
            pq.pop();
        }
        
        if(location == top.first) {
            answer = turn;
            break;
        }
    }
    
    return answer;
}
