// 최소직사각형

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* 
// 완전탐색... 시도했는데 시간초과. 아니근데 완전탐색 문제라매.

int findMinWH(vector<int> currWs, vector<int> currHs){
    int maxW = 0;
    int maxH = 0;
    
    for (int i=0; i<currWs.size(); i++){
        maxW = max(maxW, currWs[i]);
        maxH = max(maxH, currHs[i]);
    }
    return maxW * maxH;
}

int swapping(int idx, bool isSwap, vector<int> currWs, vector<int> currHs, int arrLen){
    if(idx >= arrLen) return findMinWH(currWs, currHs);
    int tempW = currWs[idx];
    int tempH = currHs[idx];
    
    if(isSwap) {
        currWs[idx]=tempH;
        currHs[idx]=tempW;
    }
    return min(swapping(idx+1, true, currWs, currHs, arrLen), swapping(idx+1, false, currWs, currHs, arrLen));
}

vector<int> ws;
vector<int> hs;

int solution(vector<vector<int>> sizes) { // sizes[i] = [w, h]
    int answer = 0;
    
    // init: find max w,h
    int maxW = 0;
    int maxH = 0;
    
    for (int i=0; i<sizes.size(); i++){
        maxW = max(maxW, sizes[i][0]);
        ws.push_back(sizes[i][0]);
        maxH = max(maxH, sizes[i][1]);
        hs.push_back(sizes[i][1]);
    }
    
    answer = min(swapping(0, true, ws, hs, sizes.size()), swapping(0, false, ws, hs, sizes.size()));
    return answer;
}
*/


/*

// 안돌렸을 때 가로 max 세로 max 찾아서 둘다 돌려보고 더 작은거 채택하기

vector<int> currWs;
vector<int> currHs;

int getArea(int tempW, int tempH, int idx, vector<vector<int>> sizes){
    int maxW = 0;
    int maxH = 0;
    
    for (int i=0; i<sizes.size(); i++){ // i번째 원소 대신 temp가 들어간다. 뒤집혀서!
        maxW = (i==idx) ? max(maxW, tempH) : max(maxW, sizes[i][0]);
        maxH = (i==idx) ? max(maxH, tempW) : max(maxH, sizes[i][1]);
    }
    
    cout << tempW << ' ' << tempH << " -> " << maxW << "*" << maxH << "=";
    
    return maxW * maxH;
}


int solution(vector<vector<int>> sizes) { // sizes[i] = [w, h]
    int answer = 0;
     // init: find max w,h
    int maxW = 0;
    int maxH = 0;
    int maxWidx = -1;
    int maxHidx = -1;
    
    for (int i=0; i<sizes.size(); i++){
        maxW = max(maxW, sizes[i][0]);
        maxH = max(maxH, sizes[i][1]);
    }
    answer = maxW * maxH;
    
    cout << "initialize: " << maxW << "*" << maxH << "=" << answer << '\n';
    
    // 1. 가로 기준으로 했을 때, 세로(maxH)를 뒤집어서 new가로가 maxW 보다 작으면 성공. 새로운 maxH 찾아서 넓이 계산하기
    
    for (int i=0; i<sizes.size(); i++){
        if (sizes[i][1] == maxH){
            cout << "swap longest H: ";
            int tempArea = getArea(sizes[i][0], sizes[i][1], i, sizes);
            answer = min(answer, tempArea);
            cout << tempArea << ' ' << answer << '\n';
        }
    }
    
    // 2. 세로 기준으로 했을 때, 가로를 뒤집어서 new세로가 maxH 보다 작으면 성공. 새로운 maxW 찾아서 넓이 계산하기
     
    for (int i=0; i<sizes.size(); i++){
        if (sizes[i][0] == maxW){
            cout << "swap longest W: ";
            int tempArea = getArea(sizes[i][0], sizes[i][1], i, sizes);
            answer = min(answer, tempArea);
            cout << tempArea << ' ' << answer << '\n';
        }
    }
    return answer;
}

*/

// 최종: w,h 다 합해서 제일 긴거 냅두고, 나머지는 명함들의 w,h 중에 min 값.

vector<vector<int>> names;

void swap(int idx){
    int tempW = names[idx][0];
    int tempH = names[idx][1];
    
    names[idx][0] = tempH;
    names[idx][1] = tempW;
}

void printNames(){
    for (int i=0; i<names.size(); i++){
        cout << names[i][0] << ' '<< names[i][1] << '\n';
    }
}

int solution(vector<vector<int>> sizes) { // sizes[i] = [w, h]
    int answer = 0;
    int maxW=0;
    int maxH=0;
    int maxWH = 0;
    
    // copy
    for(int i=0;i<sizes.size(); i++){
        names.push_back( { sizes[i][0], sizes[i][1] } );
    }
    
    // 일단 maxW, maxH
    for (int i=0; i<sizes.size(); i++){
        maxW = max(sizes[i][0], maxW);
        maxH = max(sizes[i][1], maxH);
    }
    answer = maxW * maxH;
    maxWH = max(maxW, maxH);
    
    // cout << "Before: \n";
    // printNames();
    
    if(maxWH == maxW){
        for (int i=0; i<names.size(); i++){
            if(names[i][0] != maxW) {
                if (names[i][0] < names[i][1]) swap(i);
            }
        }
    } else if (maxWH == maxH){
        for (int i=0; i<names.size(); i++){
            if(names[i][0] != maxH) {
                if (names[i][0] < sizes[i][1]) swap(i);
            }
        }
    }
    
    // maxW, maxH
    maxW = 0;
    maxH = 0;
    for (int i=0; i<names.size(); i++){
        maxW = max(names[i][0], maxW);
        maxH = max(names[i][1], maxH);
    }
    answer = maxW * maxH;
    
    // cout << "After: \n";
    // printNames();
    
    return answer;
}
