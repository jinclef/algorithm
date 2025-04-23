#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

// 아래, 오른쪽, 위, 왼쪽
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool visited[123][123];
queue<pair<pii, int>> curr;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    // init
    curr.push(make_pair(make_pair(0,0), 0));
    
    // move
    while(!curr.empty()){
        int row = curr.front().first.first;
        int col = curr.front().first.second;
        int level = curr.front().second;
        visited[row][col] = true;
        curr.pop();
        
        if(row == n-1 && col == m-1) {
            answer = level+1;
            break;
        }
        
        for(int i=0; i<4; i++){ // [row, col] 의 adj
            int nr = row + dy[i];
            int nc = col + dx[i];
            if((nr>=0 && nr < n && nc>=0 && nc<m) && maps[nr][nc] == 1 && !visited[nr][nc]) {
                curr.push(make_pair(make_pair(nr, nc), level+1));
                visited[nr][nc] = true;
            }
        }
    }
    answer = (answer == 0) ? -1 : answer;
    return answer;
}
