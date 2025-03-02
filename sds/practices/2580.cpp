#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int seudoku[9][9];
bool cand[9][9][10]; // cand[i][j][k]: (i,j) 의 후보 중 k 가 되는가.

void box(int x, int y, int val){
    
}

void line(int x, int y, int val){
    
}

void setNum(int x, int y, int val){
    seudoku[x][y] = val;
    int dx[] = {-1, 0, 1};
    int dy[] = {-1, 0, 1};

    // box
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(x+dx[i]<0 || y+dy[j]<0 || x+dx[i]>8 || y+dy[j]>8) continue; // overflow
            if(dx[i]==0 && dy[i]==0) continue; // 자기 자신
            cand[x+dx[i]][y+dy[j]][val] = false;
        }
    }
    
    // line
    for (int i=0;i<9;i++){
        if(i!=x) cand[i][y][val] = false;
        if (i!=y) cand[x][i][val] = false;
    }
}

void printMap(){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cout << seudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

vector<int> candNum(int x, int y){
    vector<int> ans;
    for (int i=1;i<=9;i++){
        if (cand[x][y][i]) ans.push_back(i);
    }
    return ans;
}

void printCands(int x, int y){
    vector<int> cands = candNum(x,y);
    cout << "candNum for (" << x << ' ' << y << ") is ";
    for (int i=0;i<cands.size(); i++){
        cout << cands[i] << ',';
    }
    cout << '\n';
}

int main(){
    // init candidate
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            for (int k=1;k<=9;k++){
                cand[i][j][k] = true;
            }
        }
    }

    // input
    int zerocount = 0;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            int value;
            cin >> value;

            if(value == 0){
                vector<int> cands = candNum(i,j);
                if (cands.size()==1){
                    setNum(i,j,cands[0]);
                }
                else zerocount++;
            } else {
                setNum(i,j,value);
            }
        }
    }

    cout << "-- input done: " << zerocount << " -- \n";
    printMap();

    while(zerocount>0){
        bool changed = false;
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                vector<int> cands = candNum(i,j);
                if (cands.size()==1){
                    seudoku[i][j] = cands[0];
                    cand[i][j][cands[0]] = false;
                    box(i,j,cands[0]);
                    line(i,j,cands[0]);
                    zerocount--;
                }
            }
        }
        if (!changed) break; // loop
    }

    cout << "-- while loop done: " << zerocount << " -- \n";
    printMap();

    // more...
    return 0;
}