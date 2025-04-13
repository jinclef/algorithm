// 완전탐색 - 모의고사

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int person1[] = {1,2,3,4,5};
int person2[] = {2,1,2,3,2,4,2,5};
int person3[] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int person1_answers=0;
    int person2_answers=0;
    int person3_answers=0;
    for (int i=0; i<answers.size(); i++){
        if(person1[i%5] == answers[i]) person1_answers++;
        if(person2[i%8] == answers[i]) person2_answers++;
        if(person3[i%10] == answers[i]) person3_answers++;
    }
    
    int temp[] = {person1_answers, person2_answers, person3_answers};
    int maxValue = 0;
    for(int i=0; i<3; i++){
        if(temp[i] >= maxValue) maxValue = temp[i];
    }
    
    for (int i=0; i<3; i++){
        if(temp[i] == maxValue) answer.push_back(i+1);
    }
    return answer;
}