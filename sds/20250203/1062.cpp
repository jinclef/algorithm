#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K; // N < 50, K < 26
int ans; // max
bool choice[26] = {false, };
string voca[26];

void printChoice(){
    for (int i =0;i<26;i++){
        cout << choice[i] << ' ';
    }
    cout << '\n';
}

void backT(int idx, int cnt){
    if (cnt >= N){ // 쌍 완성!
        printChoice();
        for (int j=0; j<N; ++j){
            string target = voca[j];
            for (int m = 0; m < target.length(); m++){
                char a = target[m];
                if (choice[a-'a'] == false){
                    cnt = -1;
                    break;
                }
            }
        }
        cout << "result cnt: " << cnt << '\n';
        ans = max(ans, cnt);
        return;
    } else if (choice[idx]) {
        cout << "pre valued: " << idx << " : " << choice[idx] << '\n';
        return; // a,n,t,i,c
    }
    backT(idx, cnt);
    choice[idx] = true;
    backT(idx+1, cnt+1);
    choice[idx] = false;
    return;
}

int main(){ ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> K;

    for (int i = 0 ; i<N; i++){
        string A;
        cin >> voca[i];
    }

    // a,n,t,i,c
    choice['a' - 'a'] = true;
    choice['n' - 'a'] = true;
    choice['t' - 'a'] = true;
    choice['i' - 'a'] = true;
    choice['c' - 'a'] = true;

    backT(0,0);
    cout << ans;
    
    return 0;
}