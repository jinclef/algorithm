// 같은 숫자는 싫어

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

queue<int> fifo;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int repeat = -1;
    
    for (int i=0; i<arr.size(); i++){
        if(arr[i] == repeat) continue;
        else {
            fifo.push(arr[i]);
            repeat = arr[i];
        }
    }
    
    while(!fifo.empty()){
        answer.push_back(fifo.front());
        fifo.pop();
    }
    
    return answer;
}