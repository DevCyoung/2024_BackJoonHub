#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};    
    char target = words[0][0];
    map<string, bool> check;    
    for (int i = 0; i < words.size(); ++i)
    {        
        if (target != words[i][0] || check[words[i]])
        {            
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;            
            break;
        }
        check[words[i]] = true;
        target = words[i].back();
    }    
    return answer;
}