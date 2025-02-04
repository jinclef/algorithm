#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K; // N < 50, K < 26
int ans; // max
bool choice[26] = {false, };
string voca[50];

void printChoice(){
    for (int i =0;i<26;i++){
        cout << choice[i] << ' ';
    }
    cout << '\n';
}

bool flag;

void backT(int idx, int cnt){
    if (cnt == K){ // 쌍 완성!
        int num=0;
        for (int j=0; j<N; ++j){
            string target = voca[j];
            flag = true;
            for (int m = 0; m < target.length(); m++){
                char a = target[m];
                if (choice[a-'a'] == false){
                    flag = false;
                    break;
                }
            }
            if(flag) {
                num++;
            }
        }
        ans = max(ans, num);
        return;
    } 
    if (idx >= 26) return;
    else if (choice[idx]) {
        // a,n,t,i,c
        backT(idx+1, cnt+1);
    }
    backT(idx+1, cnt);
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

    if (K<5){
        cout << 0 << '\n';
        return 0;
    }

    // a,n,t,i,c
    choice['a' - 'a'] = true;
    choice['n' - 'a'] = true;
    choice['t' - 'a'] = true;
    choice['i' - 'a'] = true;
    choice['c' - 'a'] = true;

    backT(0,0);
    cout << ans << '\n';
    
    return 0;
}