#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> gostack;

void numx(int x) {
	gostack.push(x);
}

void pop() {
	gostack.pop();
}

void inv() {
	gostack.push(gostack.top() * (-1));
}

void dup() {
	gostack.push(gostack.top());
}

void swp() {
	int top = gostack.top();
	gostack.pop();
	int second = gostack.top();
	gostack.pop();
	gostack.push(top);
	gostack.push(second);
}

void add() {
	int top = gostack.top();
	gostack.pop();
	int second = gostack.top();
	gostack.pop();
	int  res = top + second;
	if (res > 10 ^ 9) {
		cout << "ERROR\n";
		exit(0);
	}

	gostack.push(res);
}

void sub() {
	int top = gostack.top();
	gostack.pop();
	int second = gostack.top();
	gostack.pop();

	gostack.push(second - top);
}

void mul() {
	int top = gostack.top();
	gostack.pop();
	int second = gostack.top();
	gostack.pop();
	int res = top * second;
	if (res > 10 ^ 9) {
		cout << "ERROR\n";
		exit(0);
	}
	gostack.push(top*second);
}

int is_minus(int a, int b) {
	if (a < 0 && b >= 0) return -1;
	if (a >= 0 && b < 0) return -1;
	else return 1;
}

void div() {

	int top = gostack.top();
	gostack.pop();
	int second = gostack.top();
	gostack.pop();
	int res = abs(second) / abs(top) * is_minus(top, second);

	gostack.push(res);
}

void mod() {

	int top = gostack.top();
	gostack.pop();
	int second = gostack.top();
	gostack.pop();

	if (top == 0) {
		cout << "ERROR\n";
		exit(0);
	}

	int is_minus = (second < 0) ? -1 : 1;
	gostack.push(abs(second) % abs(top) * is_minus);
}

int runProgram(int value, queue<string> program){
    gostack.push(value);

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
    else {
        cout << "ERROR\n";
        exit(0);
    }
    

    if (gostack.size() != 1) {
        cout << "ERROR" << '\n';
        exit(0);
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
        allProgram.push(eachProgram);

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

    // run each programs
    while(!allProgram.empty() && !allValues.empty()){
        queue<int> values = allValues.front();
        queue<string> program = allProgram.front();
        while(!values.empty()){
            // run each program
            int value = values.front();
            values.pop();
            cout << runProgram(value, program) << '\n';
        }
        allProgram.pop();
    }

	return 0;
}