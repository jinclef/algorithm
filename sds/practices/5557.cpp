// 1학년

#include <iostream>
using namespace std;
typedef long long ll;

int subsum[101][2]; // subsum[i][0]: i번째 수까지의 (가능한) 누적합에 +[i+1] 했을 때 값, subsum[i][1]: i번째 수까지의 (가능한) 누적합에 -[i+1] 했을 때 값.
ll subcnt[101][2]; // " 했을 때 개수.

int N;
ll sum;
ll cnt;
int nums[101];

// ll makeSubsum(int newIdx, bool doPlus){
//     if(newIdx >=N) return 0;

//     if (doPlus) subcnt[newIdx][0] +=1; else subcnt[newIdx][1] += 1;

//     ll plusX = sum + nums[newIdx];
//     ll minusX = sum - nums[newIdx];
//     bool canPlus = (plusX >= 0 && plusX <=20);
//     bool canMinus = (minusX >= 0 && minusX <=20);


//     if(canPlus) {
//         if(subsum[newIdx][0] != -1) return subcnt[newIdx][0]; // 이미 계산된 경우
//         if(subsum[newIdx][0] == subsum[newIdx][1]) return subcnt[newIdx][1]; // 이미 이전 재귀에서 계산된 경우
//         subsum[newIdx][0] = plusX;
//         return 1 + makeSubsum(newIdx + 1, true);
//     }

//     if(canMinus) {
//         if(subsum[newIdx][1] != -1) return subcnt[newIdx][1]; // 이미 계산된 경우
//         if(subsum[newIdx][1] == subsum[newIdx][0]) return subcnt[newIdx][0]; // 이미 이전 재귀에서 계산된 경우
//         subsum[newIdx][1] = minusX;
//         return 1 + makeSubsum(newIdx + 1, false);
//     }

//     if(!canPlus && !canMinus) return 0;
// }

int savedStepSum[101];
ll savedStepCnt[101][21]; // totalCase(curIdx, curSum) = savedStepCnt[curIdx][curSum] -> -1이 아니면 재사용한다.

ll totalCase(int curIdx, int curSum){
    if(curIdx+1 == N-1) {
        if(curSum == nums[N-1]) return 1; else return 0;
    }

    if(savedStepCnt[curIdx][curSum] != -1) return savedStepCnt[curIdx][curSum];

    ll partSum = curSum + nums[curIdx+1];
    ll partSub = curSum - nums[curIdx+1];

    bool canSum = partSum >=0 && partSum <= 20;
    bool canSub = partSub >=0 && partSub <= 20;

    if (canSum && canSub)       savedStepCnt[curIdx][curSum] = totalCase(curIdx+1, partSum) + totalCase(curIdx+1, partSub);
    else if (canSum && !canSub) savedStepCnt[curIdx][curSum] = totalCase(curIdx+1, partSum);
    else if (!canSum && canSub) savedStepCnt[curIdx][curSum] = totalCase(curIdx+1, partSub);
    else                        savedStepCnt[curIdx][curSum] = 0; // 계산이 안되는 경우. 현실적으로 없음

    return savedStepCnt[curIdx][curSum];
}

int main(){
    cin >> N;

    // init
    for (int i=0; i<100; i++){
        for (int j=0; j<21; j++){
            savedStepCnt[i][j] = -1;
        }
    }

    for (int i=0; i<N; i++){
        cin >> nums[i];
    }
    
    cnt = totalCase(0, nums[0]);
    cout << cnt << '\n';

    // for (int i=0; i<100; i++){
    //     for (int j=0; j<21; j++){
    //         cout << savedStepCnt[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}