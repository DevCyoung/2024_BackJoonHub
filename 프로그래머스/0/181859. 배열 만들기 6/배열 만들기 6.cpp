#include <string>
#include <vector>

using namespace std;
//arr 0 1 -> stk
//i < arr.size()
// if stk empty stk.push_back(arr[i])

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int i = 0;
    while (i < arr.size())
    {
        if (answer.empty())
        {
            answer.push_back(arr[i]);
            ++i;
        }
        else if (*(--answer.end()) == arr[i])
        {
            answer.pop_back();
            ++i;
        }
        else
        {
            answer.push_back(arr[i]);
            ++i;
        }
    }
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}