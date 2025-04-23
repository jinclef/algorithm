#include <string>
#include <vector>
#include <queue>
using namespace std;

int visited[201];
int networks;
queue<int> groups;

void bfs(vector<vector<int>> computers, int n){
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        groups.push(i);
        
        while(!groups.empty()){
            int k = groups.front();
            for(int j=0; j<n; j++){
                if(!visited[j] && computers[k][j] == 1) {
                    groups.push(j);
                    visited[j] = true;
                }
            }
            groups.pop();
        }
        networks++;
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bfs(computers, n);
    answer = networks;
    return answer;
}
