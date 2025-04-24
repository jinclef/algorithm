#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[10000][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int level = triangle.size();  //triangle.size() == leaf node 수
    for(int i=0; i<level; i++){
        dp[level-1][i] = triangle[level-1][i];
    }
    
    
    // 밑에서부터 올라오기
    for(int i=level-2; i>=0; i--){
        for(int j=0; j<triangle[i].size(); j++){
            dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    answer = dp[0][0];
    return answer;
}
