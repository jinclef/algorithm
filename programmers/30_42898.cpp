#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

const ll prime = 1000000007;

ll dp[100][100];

void printDP(int n, int m){
        
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    dp[0][0] = 1;
    
    // 모두 1로 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = 1;       
        }
    }
    
    // 물웅덩이에서 가능한 경로 없음.
    for(int i=0; i<puddles.size(); i++){
        // puddles[i] : vector<int>. 좌표
        int x = puddles[i][0]-1;
        int y = puddles[i][1]-1;
        dp[y][x] = 0;
    }
    
    // cout << "INIT\n";
    // printDP(n,m);
    
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) continue;
            ll up = (i==0) ? 0 : dp[i-1][j] % prime;
            ll left = (j==0) ? 0 : dp[i][j-1] % prime;
            if(dp[i][j]!=0) dp[i][j] = (up+left) % prime;
            // cout << dp[i][j] << '\n';
            // printDP(n,m);
        }
    }
    
    answer = dp[n-1][m-1] % prime;
    
    return answer;
}
