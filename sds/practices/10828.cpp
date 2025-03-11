// 스택

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N;
stack<int> s;

int main(){
    cin >> N;

    for (int i=0;i<N;i++){
        string cmd;
        cin >> cmd;

        if(cmd == "push"){
            int a;
            cin >> a;
            s.push(a);
        } else if (cmd == "top"){
            if(s.size() == 0) cout << -1 << '\n';
            else cout << s.top() << '\n';
        } else if (cmd == "size"){
            cout << s.size() << '\n';
        } else if (cmd == "empty"){
            if(s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (cmd == "pop"){
            if(s.size() == 0) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }else {
            cout << "error\n"; // 실제로 일어나지 않음.
        }
    }
    return 0;
}