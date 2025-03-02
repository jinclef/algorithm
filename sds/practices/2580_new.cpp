#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int seudoku[9][9];
bool cand[9][9][10]; // cand[i][j][k]: (i,j) 의 후보 중 k 가 되는가. (i,j)의 후보는 자기 자신만 남도록 함
vector<pii> zeroCells;

void printMap(){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cout << seudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

void printCands(int x, int y){
    vector<int> ans;
    for (int i=1;i<=9;i++){
        if (cand[x][y][i]) ans.push_back(i);
    };
    cout << "candNum for (" << x << ' ' << y << ") is ";
    for (int i=0;i<ans.size(); i++){
        cout << ans[i] << ',';
    }
    cout << '\n';
}

void exceptMyLineVal(int x, int y, int val){
    // (x,y)의 세로행, 가로행에는 더이상 val 이 들어가지 못하도록 함.
    for (int i=0;i<9;i++){
        if(i!=y) cand[x][i][val] = false;
        if(i!=x) cand[i][y][val] = false;
    }
}

bool isSolved(){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            // int cnt = 0;
            // for (int v=1;v<=9;v++){
            //     if(cand[i][j][v]) cnt++;
            // }
            // if (cnt != 1) return false;
            if(seudoku[i][j]==0) return false;
        }
    }
    return true;
}

void exceptMyBoxVal(int x, int y, int val){
    // 1. 내가 속한 박스 찾기: 3으로 나눈 몫이 모두 같다
    // 2. 내가 속한 박스에 더이상 val이 들어가지 못하도록 함.
    int dx[] = {-2,-1,0,1,2};
    int dy[] = {-2,-1,0,1,2};

    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if((x+dx[i]) > 8 || (y+dy[j])>8 || (x+dx[i])<0 || (y+dy[j]) < 0 || (x+dx[i])/3 != x/3 || (y+dy[j])/3 != y/3) continue; // overflow, not my box
            if(dx[i]==0 && dy[j]==0) continue; // self
            cand[x+dx[i]][y+dy[j]][val] = false;
        }
    }
}

void putAns(int x, int y, int val){
    seudoku[x][y] = val;
    if(val!=0){
        for (int i=1;i<=9;i++){
            if(i!=val) cand[x][y][i] = false; // 내 자리 후보는 하나.
        }
    }
    exceptMyLineVal(x,y,val);
    exceptMyBoxVal(x,y,val);
    // printCands(x,y);
}

int zeros = 0;

int main(){
    
    // init candidate
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            for (int k=1;k<=9;k++){
                cand[i][j][k] = true;
            }
        }
    }

    // just input
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cin >> seudoku[i][j];
            putAns(i, j, seudoku[i][j]);
            if(seudoku[i][j] == 0) zeros++;
        }
    }

    cout << zeros << '\n';

    bool changed = false;
    bool solved = false;
    while(zeros>0){
        changed = false;
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if(seudoku[i][j]==0){
                    vector<int> ans;
                    for (int v=1;v<=9;v++){
                        if (cand[i][j][v]) ans.push_back(v);
                    }
                    if(ans.size()==1) {
                        putAns(i,j,ans[0]);
                        zeros--;
                        changed = true;
                    }
                }
            }
        }
        solved = isSolved();

        if (!changed && zeros>0) { // 더이상 해결할 수 없는 경우. 찍는다
            // try
            while(!solved){
                for (int i=0;i<9;i++){
                    for (int j=0;j<9;j++){
                        if(seudoku[i][j]==0){
                            for (int v=1;v<=9;v++){
                                if(cand[i][j][v]) {
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printMap();
    return 0;
}