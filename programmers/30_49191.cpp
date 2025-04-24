#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

map<int, pair<set<int>, set<int>>> vs; // i번째 사람이 이긴 사람들, 진 사람들: 진사람들수 +1 = 나의 순위
int ranks[102];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0; i<results.size(); i++){
        int winner = results[i][0];
        int loser = results[i][1];
        vs[winner].first.insert(loser);
        vs[loser].second.insert(winner);
    }
    
    while(true){
        bool updated = false;
        for(int i=1; i<=n; i++){
            // i번 선수가 이긴 사람들과 진 사람들
            set<int> winned = vs[i].first;
            set<int> losed = vs[i].second;

            for(auto w : winned){
                int temp = vs[w].second.size();
                for(auto k : losed){
                    vs[w].second.insert(k);
                }
                if(temp != vs[w].second.size()) updated = true;
            }
            
            for(auto l : losed){
                int temp = vs[l].first.size();
                for(auto k : winned){
                    vs[l].first.insert(k);
                }
                if(temp != vs[l].first.size()) updated = true;
            }
        }
        if(!updated) break;
    }    

    for(int i=1; i<=n; i++){
        if(vs[i].first.size() + vs[i].second.size() >= n-1) ranks[i] = vs[i].second.size()+1;
    }
    
    for(int i=1; i<=n; i++){
        if(ranks[i]!=0) {
            answer++;
        }
    }
    
    return answer;
}
