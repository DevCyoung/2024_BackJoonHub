#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> map;
    
    for (int i = 0; i < 26; ++i)
    {
        string alpha = "";
        alpha += ('A' + i);
        
        map[alpha] = i + 1;
    }
             
    for (int i = 0; i < msg.size(); ++i)
    {
        int j = i;
        string w = "";
        for (; j < msg.size(); ++j)
        {
            w += msg[j];            
            if (map[w] == 0)
            {                         
                map[w] = map.size();                                
                w.pop_back();                                                
                break;
            }            
        }
        i = j - 1;        
        answer.push_back(map[w]);
    }    
    return answer;
}