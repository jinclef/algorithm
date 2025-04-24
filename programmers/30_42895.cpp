#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

map<int, vector<ll>> subsum; // [cnt, {}] : n이 cnt개 만큼 있을 때 만들 수 있는 수의 배열

int solution(int N, int number) {
    int answer = 0;
    int n = N;
    
    int result = N;
    int cnt = 1;
    subsum[1] = {N};

    while(result != number){    
        cnt++;
        if(cnt > 8) break;
        vector<ll> temp;
        int defaultValue = 0; // NNN
        for(int i=cnt; i>0; i--){
            defaultValue += pow(10, i-1) * N;
        }
        temp.push_back(defaultValue);
        
        for(int i=1; i<cnt; i++){ // n 이 i 개 있는 값과 n 이 cnt-i 개 있는 값끼리 사칙연산해서 저장하기.
            for(int j=0; j<subsum[i].size(); j++){
                ll left = subsum[i][j];
                for(int k=0; k<subsum[cnt-i].size(); k++){
                    ll right = subsum[cnt-i][k];
                    
                    if(left+right>0) temp.push_back(left + right);
                    if(left-right>0) temp.push_back(left - right);
                    if(left*right>0) temp.push_back(left * right);
                    if(right!=0 && left/right>0) temp.push_back(left / right);
                    if(right-left>0) temp.push_back(right - left);
                    if(left!=0 && right/left>0) temp.push_back(right / left);
                }
            }
        }
        subsum[cnt] = temp;
        for(int i=0; i<subsum[cnt].size(); i++){
            if(subsum[cnt][i] == number) result = subsum[cnt][i];
        }
    }
    answer = (cnt > 8) ? -1 : cnt;
    
    return answer;
}
