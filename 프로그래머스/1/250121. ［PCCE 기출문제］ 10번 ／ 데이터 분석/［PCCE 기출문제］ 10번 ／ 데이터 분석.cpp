#include <string>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> table;    
    string extArr[4] = {"code", "date", "maximum", "remain"};
    
    for (int i = 0; i < 4; ++i)
    {
        table[extArr[i]] = i;
    }    
    
    for (int i = 0; i < data.size(); ++i)
    {        
        int idx = table[ext];
        int extValue = data[i][idx];
        
        if (extValue < val_ext)
        {
            answer.push_back(data[i]);
        }                
    }
    
    //buble sort
    for (int i = 0; i < answer.size(); ++i)
    {
        for (int j = 0; j < answer.size() - i - 1; ++j)
        {
            int idx = table[sort_by];
            
            if (answer[j][idx] > answer[j + 1][idx])
            {
                vector<int> temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }
    return answer;
}