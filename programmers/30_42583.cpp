#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> bridge;
queue<int> staying_trucks;
queue<int> passed_trucks;

// 다리 위에 있는 트럭 다 한칸씩 옮겨주기
void pass_trucks(int bridge_length){
    int idx = bridge_length-1;
    
    while(idx >= 0){
        int passing_target = bridge[idx];
        if(passing_target == -1) {idx--; continue;}
        
        bridge[idx] = -1; // 내 자리 비우기
        if(idx+1 >= bridge_length && passing_target != -1) { // 다리 다 건넌 경우
            passed_trucks.push(passing_target);
        } else { // 다음 칸으로 넘겨주기
            bridge[idx+1] = passing_target;
        }
        idx--;
    }
}

// 새로 넣어주기
void push_truck(int bridge_limit){
    if(staying_trucks.empty()) return;
    
    int truck_weight = staying_trucks.front();
    
    // 다리 하중 검토
    int bridge_sum = 0;
    for (int i=0; i< bridge.size(); i++){
        if(bridge[i] == -1) continue;
        else {
            bridge_sum += bridge[i];
        }
    }
    if(bridge_sum + truck_weight > bridge_limit) return;
    else {
        bridge[0] = truck_weight;
        staying_trucks.pop();
    }
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truck_cnt = truck_weights.size();
    
    // make staying queue
    for (int i=0; i<truck_weights.size(); i++){
        staying_trucks.push(truck_weights[i]);
    }
    
    // init bridge
    for (int i=0; i<bridge_length; i++){
        bridge.push_back(-1);
    }
    
    while(!staying_trucks.empty() || passed_trucks.size() < truck_cnt){
        pass_trucks(bridge_length);
        if(bridge[0] == -1) {
            push_truck(weight);
        }
        answer++;
    }
    return answer;
}
