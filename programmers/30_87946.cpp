//피로도 - 실패

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    if(a[0] != b[0]) return a[0] > b[0];
    else return a[1] < b[1];
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    // 1. 최소 필요 피로도 기준 정렬
    sort(dungeons.begin(), dungeons.end(), compare);
    
    // 2. currTired - [i][1] >= [i+1][0] ?
    int currTired = k;
    int cnt = 1;
    
    for (int curr=0; curr<dungeons.size(); curr++){
        for (int i=0; i<dungeons.size(); i++){
            if(i==curr) continue;
            if(i >= dungeons.size()) break;
            if(currTired - dungeons[curr][1] >= dungeons[i][0]){
                // 소모하고 다음으로 넘어간다.
                currTired -= dungeons[curr][1];
                curr = i;
                cnt++;
                // 안 소모하고 넘어가는 경우가 포함되어야 함.
                
            } else {
                // 소모하지 않고 다음으로 넘어간다.
                continue;
            }
        }
        answer = max(answer, cnt);
    }
    
    return answer;
}