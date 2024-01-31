#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothesArray) {
    int answer = 1;
    map<string, int> map;    
    for (vector<string>& clothes : clothesArray)
    {        
        ++map[clothes[1]];
    }
    
    std::map<string, int>::iterator iter = map.begin();
    for (; iter != map.end(); ++iter)
    {
        answer *= iter->second + 1;
    }
    
    return answer - 1;
}