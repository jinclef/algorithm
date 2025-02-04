#include <iostream>
const int MAX_LEN=15;

using namespace std;
bool visited[MAX_LEN+1][MAX_LEN+1];

int N, ans, cnt;

void initVisit(){
    for (int i =0;i<N;i++)
        for (int j=0;j<N;j++)
            visited[i][j]=false;
}

void putQueen(int row){
    if (cnt == N) { // row == N-1
        ans++;
        cnt = 0;
        initVisit();
        return;
    }
    if (row > N) {ans=0; return; } // 어차피 못오긴 함.
    
    // 현재 row에서 넣을 수 있는지 본다.
    for (int y=0; y<N; ++y){
        bool flag = true;
        if (row == 0){
            visited[row][y] = true;
            cnt++;
            putQueen(row+1);
            visited[row][y]=false;
        } else{        
            // check col
            for (int x=0;x<row;++x){
                if(visited[x][y]) {
                    flag = false;
                    break;
                }
            }
            // check diag
            if(flag){
                // right diag
                int temprx= row-1;
                int tempry = y+1;
                while(temprx>=0 && tempry<N){
                    if(visited[temprx][tempry]) {
                        flag=false; break;
                    }
                    temprx--, tempry++;
                }
                if(flag){
                    // left diag
                    int templx = row-1;
                    int temply = y-1;
                    while(templx>=0 && temply>=0){
                        if(visited[templx][temply]) {
                            flag = false; break;
                        }
                        templx--, temply--;
                    }
                }
            }
            if(flag) {// success
                visited[row][y] = true;
                cnt++;
                putQueen(row+1);
                visited[row][y] = false;
            }
        }
    }
}

int main(){
    cin >> N;
    // init field
    initVisit();
    putQueen(0);
    cout << ans << '\n';
    return 0;
}