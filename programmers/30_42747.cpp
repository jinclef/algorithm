// H-Index
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// 논문 인용 수 기준 정렬
// 같은 값이 들어 있는 경우에 대해서 처리 필요.
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int tempH = citations[0];
    
    // 1. 내림차순 정렬
    sort(citations.begin(), citations.end());
    
    // 2. 최대 h 찾기
    int answerH = -1;
    int moreThanAns = citations.size();
    for(int h_idx=0; h_idx<citations.size(); h_idx++){ // 내가 i번째 idx
        int lessThan = h_idx;
        int moreThan = citations.size() - h_idx;
        
        if(lessThan <= citations[h_idx] && moreThan >= citations[h_idx]){
            answer = max(answer, citations[h_idx]); // 확정적으로 citations[h_idx]
            answerH = h_idx;
            moreThanAns = moreThan;
        }
    }
    
    // 배열 사이에 있을 수도.
    int tempAns = answer;
    if(answerH+1 < citations.size()){
        for (int i=tempAns; i<citations[answerH+1]; i++){
            if(answerH == -1 && i <= moreThanAns) answer = i;
            else if (answerH != -1 && i <= moreThanAns-1) answer = i;
        }
    }
    
    return answer;
}
