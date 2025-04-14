// 전력망을 둘로 나누기 - 실패
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int edges[101];

int findMyGroup(int target, int cnt, bool visited[101], vector<vector<int>> brokenWires){
    for (int i=0; i< brokenWires.size(); i++){
        if (brokenWires[i][0] == target) {
            if(visited[brokenWires[i][0]]) continue;
            visited[brokenWires[i][1]] = true;
            target = brokenWires[i][1];
            findMyGroup(target, ++cnt, visited, brokenWires);
        }
        if (brokenWires[i][1] == target) {
            if(visited[brokenWires[i][1]]) continue;
            visited[brokenWires[i][0]] = true;
            target = brokenWires[i][0];
            findMyGroup(target, ++cnt, visited, brokenWires);
        }
    }
    return cnt;
}


// 그냥 다리 제일 많이 달려있는거 찾아서 걔의 전선 다 잘라보기
int solution(int n, vector<vector<int>> wires) {
    int answer = 0;
    
    // 1. 가장 다리 많이 달린 거 찾기
    // 1-1. 다리 개수
    for (int i=0; i<wires.size(); i++){
        int s = wires[i][0];
        int e = wires[i][1];
        edges[s]++;
        edges[e]++;
    }
    
    int maxEdge = 0;
    // 1-2. 가장 큰 다리
    for(int i=0; i<101; i++){
        if(maxEdge <= edges[i]) {
            maxEdge = edges[i];
        }
    }
    vector<vector<int>> maxEdgeNodes;
    for (int i=0; i<wires.size(); i++){
        if (edges[wires[i][0]] == maxEdge || edges[wires[i][1]] == maxEdge){
            maxEdgeNodes.push_back(wires[i]);
        }
    }
    
    // 2. 다 잘라보기
    for (int i=0; i<maxEdgeNodes.size(); i++){
        int leftCnt = 0;
        for (int w=0; w<wires.size(); w++){
            if (wires[w][0] == maxEdgeNodes[i][0] &&
                wires[w][1] == maxEdgeNodes[i][1]) continue;
            if (wires[w][0] > maxEdgeNodes[i][0]) break;
            leftCnt++;
        }
        int rightCnt = wires.size() - leftCnt - 1;
        
        // cout << "cut " << '[' << maxEdgeNodes[i][0] << ',' << maxEdgeNodes[i][1] << ']' << ':' << leftCnt << '_' << rightCnt << '\n';
        answer = (i==0) ? abs(rightCnt - leftCnt) : min(abs(rightCnt - leftCnt), answer);
    }
    return answer;
}