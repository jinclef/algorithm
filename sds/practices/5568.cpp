// 카드 놓기
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int n,k;
int arr[11]; // input
vector<string> res;
bool chosen[11]; // select (create nums)

void printChosen(){
    for (int i=0; i<n; i++){
        if(chosen[i]) cout << i << ' ';
    }
}

void addToRes(){
    string a;
    for (int i=0; i<n; i++){
        if(chosen[i]) a.append(to_string(arr[i]));
    }
    res.push_back(a);
}

void backTracking(int curr, int cnt){
    if (curr > n) return; // 배열 끝까지 모두 탐색
    if (cnt == k) addToRes();
    
    chosen[curr] = true;
    backTracking(curr+1, cnt+1);
    chosen[curr] = false;
    backTracking(curr+1, cnt);
}

int main(){
    cin >> n;
    cin >> k;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    backTracking(0, 0);
    cout << res.size() << '\n';

    return 0;
}