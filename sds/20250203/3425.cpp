#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

stack<int> gostack;

//! int형 함수로 다 바꾸기.
bool checkEmpty(){
    if(gostack.empty()) {
        cout << "ERROR\n";
        gostack.push(-1);
        return false;
    }
    return true;
}

void numx(int x) {
	gostack.push(x);
}

void pop() {
    checkEmpty();
	gostack.pop();
}

void inv() {
    checkEmpty();
    int top = gostack.top();
    gostack.pop();
	gostack.push(top* (-1));
}

void dup() {
	gostack.push(gostack.top());
}

void swp() {
    checkEmpty();
	int top = gostack.top();
	gostack.pop();
    
    checkEmpty();
	int second = gostack.top();
	gostack.pop();

	gostack.push(top);
	gostack.push(second);
}

void add() {
    checkEmpty();
	int top = gostack.top();
	gostack.pop();
	
    checkEmpty();
    int second = gostack.top();
	gostack.pop();

	if (abs(top + second) > pow(10,9)) {
        cout << "ERROR\n";
        if(gostack.empty()) gostack.push(-1);
        return;
	}
    int res = top + second;
	gostack.push(res);
}

void sub() {
    
    checkEmpty();
	int top = gostack.top();
	gostack.pop();
	
    checkEmpty();
    int second = gostack.top();
	gostack.pop();

	gostack.push(second - top);
}

void mul() {
    
    checkEmpty();
	int top = gostack.top();
	gostack.pop();
	
    checkEmpty();
    int second = gostack.top();
	gostack.pop();

	if (abs(top * second) > pow(10,9)) {
        cout << "ERROR\n";
        if(gostack.empty()) gostack.push(-1);
        return;
	}
	int res = top * second;
	gostack.push(res);
}

int is_minus(int a, int b) {
	if (a < 0 && b >= 0) return -1;
	if (a >= 0 && b < 0) return -1;
	else return 1;
}

void div() {
    checkEmpty();
	int top = gostack.top();
	gostack.pop();
	
    checkEmpty();
    int second = gostack.top();
	gostack.pop();

    if (top == 0) {
        cout << "ERROR\n";
        if(gostack.empty()) gostack.push(-1);
        return;
	}

	int res = abs(second) / abs(top) * is_minus(top, second);

	gostack.push(res);
}

void mod() {
    
    checkEmpty();
	int top = gostack.top();
	gostack.pop();
	
    checkEmpty();
    int second = gostack.top();
	gostack.pop();

	if (top == 0) {
        cout << "ERROR\n";
        if(gostack.empty()) gostack.push(-1);
        return;
	}

	int is_minus = (second < 0) ? -1 : 1;
	gostack.push(abs(second) % abs(top) * is_minus);
}

int runProgram(int value, queue<string> program){
    gostack.push(value);

    while(!program.empty()){
        string command = program.front();
        program.pop();

        if (command == "NUM"){
            int x = stoi(program.front());
            program.pop();
            numx(x);
        }
        else if (command == "POP") pop();
        else if (command == "INV") inv();
        else if (command == "DUP") dup();
        else if (command == "SWP") swp();
        else if (command == "ADD") add();
        else if (command == "SUB") sub();
        else if (command == "MUL") mul();
        else if (command == "DIV") div();
        else if (command == "MOD") mod();
        else if (command == "END") {
            break;
        }
        else {
            cout << "ERROR\n";
            return -1;
        }
    }

    if (gostack.size() != 1) {
        cout << "ERROR\n";
        while(!gostack.empty()) gostack.pop();
        return -1;
    }

    int res = gostack.top();
    gostack.pop();
    return res;
}

int x = 0;
queue<queue<string>> allProgram;
queue<queue<int>> allValues;

int main() {
    bool flag = true; // QUIT

	while (flag) {
		// 프로그램 영역
        queue<string> eachProgram;
        while(true){
            string command;
            cin >> command;

            if (command == "QUIT") {
                flag = false;
                break;
            }
            
            eachProgram.push(command);
            if (command == "NUM") {
                cin >> x;
                eachProgram.push(to_string(x));
            }
            
            if(command == "END"){
                break;
            }
        }
        if (eachProgram.size() > 0)
            allProgram.push(eachProgram);
        if (!flag) break;

		int N; // 수행 횟수
		cin >> N;
        queue<int> value;
		for (int i = 0; i < N; i++) {
			int k;
            cin >> k;
            value.push(k);
		}
        allValues.push(value);
	}

    // run programs
    while(!allProgram.empty() && !allValues.empty()){
        queue<int> values = allValues.front();
        queue<string> program = allProgram.front();
        while(!values.empty()){
            // run each program
            int value = values.front();
            values.pop();
            int res = runProgram(value, program);
            if (res == -1) continue;
            cout << res << '\n';
        }
        allProgram.pop();
        allValues.pop();
        cout << '\n';
    }

	return 0;
}