#include <iostream>
using namespace std;
typedef long long ll;

int main(){ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while(cin >> n){    
        ll mod = 1; // 1 % n
        ll answer = 1;

        if(n%2 == 0 || n%5 == 0){
            cout << "Invalid input: " << n << '\n';
            continue;
        }

        if (n==1) {
            cout << 1 << '\n';
            continue;
        }

        while(mod!=0){
            mod = (mod*10 + 1) % n;
            answer++;
        }
        cout << answer << endl;
    }
    return 0;
}