#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_LEN = 26;

int N,K,CNT,ans;
string voca[51];
long long vocabit[51];

void backt(int idx, int cnt, long long choice){
    if(cnt == CNT){
        int temp = 0 ;
        for (int i = 0; i<N;++i){
            // compare voca and choice
            if ((vocabit[i] & choice) == vocabit[i]) temp++;
        }
        ans = max(ans, temp);
        return;
    }
    if (idx >= MAX_LEN) return;
    if (choice & (1<<idx)) {
        backt(idx+1, cnt, choice); // already chosen
    }
    else {
        //1. not choose
        backt(idx+1, cnt, choice);
        //2. choose
        backt(idx+1, cnt+1, (choice | (1<<(idx+1))));
    }
}

int main(){
    cin >> N >> K;
    for (int i=0;i<N;++i){
        cin >> voca[i];
        for (int j=0;j<voca[i].size(); ++j){
            char a = voca[i][j];
            vocabit[i] |= 1 << (a-'a');
        }
    }

    long long choice = 0;
    // choices
    choice |= 1 << ('a' - 'a');
    choice |= 1 << ('n' - 'a');
    choice |= 1 << ('t' - 'a');
    choice |= 1 << ('i' - 'a');
    choice |= 1 << ('c' - 'a');
    
    CNT = K-5;
    if(CNT < 0) cout << 0 << '\n';
    else {
        backt(0,0,choice);
        cout << ans << '\n';
    }

    return 0;
}