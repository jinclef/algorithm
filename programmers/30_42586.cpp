#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> funcs;
    int deploy = 0;
    
    for (int i=0; i<progresses.size(); i++){
        pair<int, int> job = make_pair(progresses[i], speeds[i]);
        funcs.push(job);
    }
    
    pair<int, int> top = funcs.front();
    int popDuration = (int)ceil((double)(100 - top.first) / top.second);
    
    while(!funcs.empty()){
        top = funcs.front();
        int duration = (int)ceil((double)(100 - top.first) / top.second);
        
        if(duration <= popDuration) {
            funcs.pop();
            deploy++;
        } else {
            answer.push_back(deploy);
            popDuration = duration;
            deploy = 0;
        }
        
        if(funcs.empty()){
            answer.push_back(deploy);
        }
    }
    return answer;
}
