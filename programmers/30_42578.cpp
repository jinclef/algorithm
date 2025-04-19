#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
map<string, int> types;
set<string> type_names;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (int i=0; i<clothes.size(); i++){
        string value = clothes[i][0];
        string key = clothes[i][1];
        type_names.insert(key);
        types[key] += 1;
    }
    for (auto a: type_names){
        answer *= types[a]+1;
    }
    answer -=1;
    return answer;
}
