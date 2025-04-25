#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool isLegal(vector<string> places){
    vector<pair<int, int>> people;
    bool legal = true;
    
    // 1. P 위치 배열 담기
    for(int i=0; i<places.size(); i++){
        for(int j=0; j<places[i].length(); j++){
            // cout << places[i][j] << ' ';
            if (places[i][j] == 'P'){
                people.push_back(make_pair(i,j));
            }
        }
        // cout << '\n';
    }
    
    // 2. P 배열에 대해 맨헤튼 거리 검사
    for(int i=0; i<people.size(); i++){
        for(int j=0; j<people.size(); j++){
            int r1 = people[i].first;
            int c1 = people[i].second;
            int r2 = people[j].first;
            int c2 = people[j].second;
            int md = abs(r1-r2) + abs(c1-c2);
            
            // if(md>0 && md<=2) cout << r1 << ',' << c1 << " & " << r2 << ',' << c2 << ": cand for validate md\n";
            
            int temp_r1 = r1;
            int temp_r2 = r2;
            int temp_c1 = c1;
            int temp_c2 = c2;
            if(md>0 && md<=2){ // 3. 칸막이 검사
                vector<int> dx;
                dx.push_back(0);
                vector<int> dy;
                dy.push_back(0);
                while(r1!=r2 || c1!=c2){
                    if(r1<r2) {dy.push_back(1); r1++;}
                    else if(r1>r2) {dy.push_back(-1); r1--;}
                    
                    if(c1<c2) {dx.push_back(1); c1++;}
                    else if(c1>c2) {dx.push_back(-1); c1--;}
                }
                
                r1 = temp_r1;
                r2 = temp_r2;
                c1 = temp_c1;
                c2 = temp_c2;
                
                int xnum = 0;
                for(int i=0; i<dy.size(); i++){
                    for(int j=0; j<dx.size(); j++){
                        if(i==0 && j==0) continue;
                        int y = r1 + dy[i];
                        int x = c1 + dx[j];
                        // cout << y << ' '<< x << ' ' << places[y][x] << '\n';
                        if(places[y][x] == 'X') xnum++;
                    }
                }
                if(xnum < md) return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0; i<places.size(); i++){
        int res = isLegal(places[i]) ? 1 : 0;
        answer.push_back(res);
    }
    
    // int res = isLegal(places[2]) ? 1 : 0;
    // answer.push_back(res);
    
    return answer;
}
