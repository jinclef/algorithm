#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<string, string> pss;

vector<bool> visited; // 항공권 탐색 여부
map<string, vector<string>> lines; // 출발: 도착...

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    // ticket 초기화
    for(int i=0; i<tickets.size(); i++){
        lines[tickets[i][0]].push_back(tickets[i][1]);
        visited.push_back(false);
    }
    
    for (int i=0; i<tickets.size(); i++){
        sort(lines[tickets[i][0]].begin(), lines[tickets[i][0]].end());
    }
    
    // ICN 시작으로 방문
    string begin = "ICN";
    answer.push_back(begin);
    
    int cnt = 0;
    while(cnt < tickets.size()){
        string arrival = lines[begin][0];
        lines[begin].erase(lines[begin].begin());
        answer.push_back(arrival);
        begin = arrival;
        cnt++;
    }
    return answer;
}
