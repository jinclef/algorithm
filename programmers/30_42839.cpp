// 완전탐색 - 소수 찾기

#include <string>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

const ll MAX_VALUE = 10000000; //  길이 7 -> 9999999 -> 10000000
bool complex[MAX_VALUE]; // 1~9999999. false로 초기화. false면 prime.

void eratos(){
    complex[0] = true;
    complex[1] = true;
    for (ll i=2; i*i<MAX_VALUE; i++){
        if(complex[i]) continue;
        for (ll j=i*i; j<MAX_VALUE; j+=i){
            complex[j] = true;
        }
        complex[i] = false;
    }
}

bool checkPrime(int p){
    return !complex[p];
}

int nums[8];
vector<string> numsets;
set<int> numset;

void backtrack(string curr, bool used[], int len){
    if(!curr.empty()) {
        numset.insert(stoi(curr));
    }
    
    for (int i=0; i<len; i++){
        if(used[i]) continue;
        
        used[i] = true;
        backtrack(curr + to_string(nums[i]) , used, len);
        used[i] = false;
    }
}


int solution(string numbers) {
    int answer = 0;
    
    for (int i=0; i<numbers.length(); i++){
        char k = numbers[i];
        nums[i] = k - '0';
    }

    // 1. 가능한 조합 string 모두 만들기
    bool used[8] = {false};
    backtrack("", used, numbers.length());
    
    
    // 2. set 돌면서 prime 인지 확인
    eratos();
    
    for (auto p : numset){
        if (checkPrime(p)) answer++;
    }
    
    return answer;
}