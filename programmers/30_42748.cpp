#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int t=0; t<commands.size(); t++){
        int parseFrom = commands[t][0];
        int parseTo = commands[t][1];
        int getAt = commands[t][2];
        
        // 1. parse
        vector<int> temp;
        for (int i=1; i<=array.size(); i++){
           int idx = i-1;
            if(parseFrom <= i && i <= parseTo){
                temp.push_back(array[idx]);
            }
        }

        // 2. sort
        sort(temp.begin(), temp.end());

        // 3. find
        answer.push_back(temp[getAt-1]);
    }
    return answer;
}