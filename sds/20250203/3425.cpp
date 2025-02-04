#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

stack<long long> gostack;
bool error;

bool checkEmptyError() {
	if (gostack.empty()) {
		cout << "ERROR: NIL\n";
		error = true;
		return true;
	}
	return false;
}

int is_minus(int a, int b) {
	if (a < 0 && b >= 0) return -1;
	if (a >= 0 && b < 0) return -1;
	else return 1;
}

int runProgram(int value, queue<string> program) {
	gostack.push(value);

	while (!program.empty()) {
		string command = program.front();
		program.pop();

		if (command == "NUM") {
			int x = stoi(program.front());
			program.pop();

			gostack.push(x);
		}
		else if (command == "POP") {
			if(checkEmptyError()) break;
			gostack.pop();
		}
		else if (command == "INV") {
			if(checkEmptyError()) break;
			long long top = gostack.top();
			gostack.pop();
			gostack.push(top* (-1));
		}
		else if (command == "DUP") {
			if (checkEmptyError()) break;
			gostack.push(gostack.top());
		}
		else if (command == "SWP") {
			if(checkEmptyError()) break;
			long long top = gostack.top();
			gostack.pop();

			if(checkEmptyError()) break;
			long long second = gostack.top();
			gostack.pop();

			gostack.push(top);
			gostack.push(second);
		}
		else if (command == "ADD") {
			if(checkEmptyError()) break;
			long long top = gostack.top();
			gostack.pop();

			if(checkEmptyError()) break;
			long long second = gostack.top();
			gostack.pop();

			if (abs(top + second) > pow(10, 9)) {
				cout << "ERROR\n" ;
				error = true;
				while (!gostack.empty()) gostack.pop();
				return -1;
			}
			gostack.push(top + second);
		}
		else if (command == "SUB") {
			if(checkEmptyError()) break;
			long long top = gostack.top();
			gostack.pop();

			if(checkEmptyError()) break;
			long long second = gostack.top();
			gostack.pop();

			if (abs(second - top) > pow(10, 9)) {
				cout << "ERROR\n";
				error = true;
				while (!gostack.empty()) gostack.pop();
				return -1;
			}

			gostack.push(second - top);
		}
		else if (command == "MUL") {
			if(checkEmptyError()) break;
			long long top = gostack.top();
			gostack.pop();

			if(checkEmptyError()) break;
			long long second = gostack.top();
			gostack.pop();
			if (abs(top * second) > pow(10, 9)) {
				cout << "ERROR\n";
				error = true;
				while (!gostack.empty()) gostack.pop();
				return -1;
			}
			int res = top * second;
			gostack.push(res);
		}
		else if (command == "DIV") {

			if(checkEmptyError()) break;
			long long top = gostack.top();
			gostack.pop();

			if(checkEmptyError()) break;
			long long second = gostack.top();
			gostack.pop();

			if (top == 0) {
				cout << "ERROR\n";
				error = true;
				while (!gostack.empty()) gostack.pop();
				return -1;
			}

			int res = abs(second) / abs(top) * is_minus(top, second);

			gostack.push(res);
		}
		else if (command == "MOD") {
			if(checkEmptyError()) break;
			long long top = gostack.top();
			gostack.pop();

			if(checkEmptyError()) break;
			long long second = gostack.top();
			gostack.pop();

			if (top == 0) {
				cout << "ERROR\n";
				error = true;
				while (!gostack.empty()) gostack.pop();
				return -1;
			}

			int is_minus = (second < 0) ? -1 : 1;
			gostack.push(abs(second) % abs(top) * is_minus);
		}
		else if (command == "END") {
			break;
		}
		else {
			cout << "ERROR\n";
			error = true;
			return -1;
		}
	}

	if (gostack.size() != 1) {
		cout << "ERROR\n";
		error = true;
		while (!gostack.empty()) gostack.pop();
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
		while (true) {
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

			if (command == "END") {
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
	while (!allProgram.empty() && !allValues.empty()) {
		queue<int> values = allValues.front();
		queue<string> program = allProgram.front();
		while (!values.empty()) {
			// run each program
			int value = values.front();
			values.pop();
			error = false;
			int res = runProgram(value, program);
			if (error) continue;
			cout << res << '\n';
		}
		allProgram.pop();
		allValues.pop();
		cout << '\n';
	}

	return 0;
}
