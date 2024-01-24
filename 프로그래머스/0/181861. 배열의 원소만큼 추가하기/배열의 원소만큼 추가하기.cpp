#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        answer.insert(answer.end(), arr[i], arr[i]);
    }
    
    
    return answer;
}