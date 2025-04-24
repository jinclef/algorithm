#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int, int> pii;

bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0]) return a[1] < b[1];
    else return a[0] < b[0];
}

bool compare_pii(pii a, pii b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

bool visited_vertex[50001];
bool visited_node[20001];
queue<pair<int, int>> adj;

vector<pii> levels;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++) if(edge[i][0] > edge[i][1]) swap(edge[i][0], edge[i][1]);
    sort(edge.begin(), edge.end(), compare);
    
    adj.push(make_pair(0,1)); // weight, node
    
    while(!adj.empty()){
        int haveadj = false;
        int weight = adj.front().first; // 부모 레벨
        int node = adj.front().second; // 부모
        levels.push_back(make_pair(weight, node));
        
        for(int i=0; i<edge.size(); i++){ // i: 간선
            if(edge[i][0] == node || edge[i][1] == node){
                int another = (edge[i][0] == node) ? edge[i][1] : edge[i][0];
                if(!visited_vertex[i]){
                    if(!visited_node[another]) {
                        adj.push(make_pair(weight+1, another));
                        visited_node[another] = true;
                        haveadj = true;
                    }
                    visited_vertex[i] = true;
                }
            }
        }
        adj.pop();
    }
    sort(levels.begin(), levels.end(), compare_pii);
    int maxLevel = levels[levels.size()-1].first;
    for(int i=levels.size()-1; i>=0; i--){
        if(levels[i].first == maxLevel) answer++;
    }
    // answer = adj.size();
    return answer;
}
