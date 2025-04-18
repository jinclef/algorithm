#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> marathon;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // run!
    for(int i=0; i<participant.size(); i++){
        marathon[participant[i]]++;
    }
    
    // complete!
    for(int i=0; i<completion.size(); i++){
        marathon[completion[i]]--;
    }
    
    // remain?
    for(int i=0; i<participant.size(); i++){
        if(marathon[participant[i]] == 0) continue;
        else {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}
