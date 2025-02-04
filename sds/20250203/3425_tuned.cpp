#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

stack<long long> gostack;
queue<queue<string>> allprograms;
queue<queue<long long>> allvalues;
bool error;

void numx(long long x) {
	gostack.push(x);
}

void pop() {
	if (gostack.empty()) {
		//cout << "pop error\n";
		error = true; return;
	}
	else gostack.pop();
}

void inv() {
	if (gostack.empty()) {
		//cout << "inv error\n";
		error = true; return;
	}
	else {
		long long top = gostack.top();
		gostack.pop();
		gostack.push(top*(-1));
	}
}

void dup() {
	if (gostack.empty()) {
		//cout << "dup error\n";
		error = true; return;
	}
	else {
		long long top = gostack.top();
		gostack.push(top);
	}
}

// 이항연산자

void swp() {
	if (gostack.size() < 2) {
		//cout << "swp error\n";
		error = true;
		return;
	}
	else {
		long long first = gostack.top();
		gostack.pop();
		long long second = gostack.top();
		gostack.pop();
		
		gostack.push(first);
		gostack.push(second);
	}
}

long long add() {
	if (gostack.size() < 2) {
		//cout << "add error\n";
		error = true; return 0;
	}
	else {
		long long first = gostack.top();
		gostack.pop();
		long long second = gostack.top();
		gostack.pop();
		//cout << first << '+' << second << '\n';
		return first + second;
	}
}

long long sub() {
	if (gostack.size() < 2) {
		//cout << "sub error\n";
		error = true; return 0;
	}
	else {
		long long first = gostack.top();
		gostack.pop();
		long long second = gostack.top();
		gostack.pop();

		return second - first;
	}
}

long long mul() {
	if (gostack.size() < 2) {
		//cout << "mul error\n";
		error = true; return 0;
	}
	else {
		long long first = gostack.top();
		gostack.pop();
		long long second = gostack.top();
		gostack.pop();

		return first * second;
	}
}

long long div() {
	if (gostack.size() < 2) {
		//cout << "div error\n";
		error = true; return 0;
	}
	else {
		long long first = gostack.top();
		gostack.pop();
		long long second = gostack.top();
		gostack.pop();

		if (first == 0) {
			//cout << "div 0 error\n";
			error = true; return 0;
		}
		else {
			// check sign
			int sign = (first * second < 0) ? -1 : 1;
			return (abs(second) / abs(first) * sign);
		}
	}
}

long long mod() {
	if (gostack.size() < 2) {
		//cout << "mod error\n";
		error = true; return 0;
	}
	else {
		long long first = gostack.top();
		gostack.pop();
		long long second = gostack.top();
		gostack.pop();

		if (first == 0) {
			//cout << "mod 0 error\n";
			error = true; return 0;
		}
		else {
			int sign = (second < 0) ? -1 : 1;
			return (abs(second) % abs(first) * sign);
		}
	}
}

void runprogram(long long v, queue<string> program) {
	if (abs(v) > pow(10, 9)) { error = true; return; }
	gostack.push(v);

	while (!program.empty()) {
		string command = program.front();
		program.pop();
		if (command == "NUM") {
			long long x = stoll(program.front());
			program.pop();
			numx(x);
			if (error) break;
		}
		else if (command == "POP") {
			pop();
			if (error) break;
		}
		else if (command == "INV") {
			inv();
			if (error) break;
		}
		else if (command == "DUP") {
			dup();
			if (error) break;
		}
		// 이항 연산자.
		else if (command == "SWP") {
			swp();
			if (error) break;

		}
		else if (command == "ADD") {
			long long res = add();
			if (abs(res) > pow(10, 9)) error = true;
			if (error) break;
			gostack.push(res);

		}
		else if (command == "SUB") {
			long long res = sub();
			if (abs(res) > pow(10, 9)) error = true;
			if (error) break;
			gostack.push(res);

		}
		else if (command == "MUL") {
			long long res = mul();
			if (abs(res) > pow(10, 9)) error = true;
			if (error) break;
			gostack.push(res);

		}
		else if (command == "DIV") {
			long long res = div();
			if (abs(res) > pow(10, 9)) error = true;
			if (error) break;
			gostack.push(res);

		}
		else if (command == "MOD") {
			long long res = mod();
			if (abs(res) > pow(10, 9)) error = true;
			if (error) break;
			gostack.push(res);
		}
		else { // "END"
			break;
		}
	}

	if (error || gostack.size()!=1) {
		cout << "ERROR\n";
		while (!gostack.empty()) {
			//cout << gostack.top() << '\n';
			gostack.pop();
		}
		return;
	}
	else {
		long long ans = gostack.top();
		gostack.pop();
		cout << ans << '\n';
		return;
	}
}

int n;
int main() {
	// 입력 받기
	queue<string> program;
	while (true) {
		string cmd;
		cin >> cmd;
		if (cmd == "QUIT") break;

		program.push(cmd);
		if (cmd == "END") {
			allprograms.push(program);
			while (!program.empty()) program.pop();
			queue<long long> values;
			cin >> n;
			for (int i = 0; i < n; ++i) {
				long long v;
				cin >> v;
				values.push(v);
			}
			allvalues.push(values);
		}
	}

	// 기계어 수행하기
	while (!allprograms.empty() && !allvalues.empty()) {
		queue<long long> eachValue = allvalues.front();
		queue<string> eachprogram = allprograms.front();
		allvalues.pop();
		allprograms.pop();

		while (!eachValue.empty()) {
			error = false;
			runprogram(eachValue.front(), eachprogram);
			eachValue.pop();
		}
		cout << '\n';
	}
	return 0;
}
