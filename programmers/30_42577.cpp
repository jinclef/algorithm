#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    int curr_idx = 0;
    
    while(curr_idx < phone_book.size()-1){
        string prefix = phone_book[curr_idx];
        string target = phone_book[curr_idx+1].substr(0, prefix.length());
        if(prefix == target) {
            answer = false;
            break;
        }
        curr_idx++;
    }
    return answer;
}
