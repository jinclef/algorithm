#include <vector>
#include <set>
using namespace std;

set<int> pocketmon;

int solution(vector<int> nums)
{
    int answer = 0;
    int takeNum = nums.size();
    for(int i=0; i<nums.size(); i++){
        pocketmon.insert(nums[i]);
    }
    
    if(pocketmon.size() >= takeNum/2) answer = takeNum/2;
    else answer = pocketmon.size();
    return answer;
}
