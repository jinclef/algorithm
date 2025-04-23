#include <string>
#include <vector>
#include <iostream>

using namespace std;

int total;

void dfs(int i, int sum, int target, vector<int> numbers){
    if(i >= numbers.size()) {
        if (sum == target) {
            total++;
        }
        return;
    }
    
    dfs(i+1, sum + numbers[i], target, numbers);
    dfs(i+1, sum - numbers[i], target, numbers);
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    // dfs(1, 0+numbers[0], target, numbers);
    // dfs(1, 0-numbers[0], target, numbers);
    dfs(0, 0, target, numbers);
    answer = total;
    return answer;
}
