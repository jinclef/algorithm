#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 100000;

char letters[MAX+1];

bool compare(char a, char b) {return a>b;}

int main(){
    string N;
    cin >> N;

    for (int i=0;i<N.length();i++){
        letters[i] = N[i];
    }

    // 0 개수 세기
    int zeros=0;
    ll lettersum = 0;
    for (int i=0;i<N.length();i++){
        if(letters[i]=='0') zeros++;
        else lettersum += (letters[i]-'0');
    }

    if (zeros == 0 || lettersum%3!=0) { // "30"을 만들려면 0이 꼭 필요하고, 합이 3의 배수여야 함.
        cout << -1 << '\n';
        return 0;
    }
    
    // 가장 큰 수부터 돌아보자!
    sort(letters, letters+N.length(), compare);

    // max num 만들기
    string maxnumstr = "";
    for (int i=0;i<N.length();i++){
        maxnumstr += letters[i];
    }

    cout <<maxnumstr << '\n';
    
    return 0;
}