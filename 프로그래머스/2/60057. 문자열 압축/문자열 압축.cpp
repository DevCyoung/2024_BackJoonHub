#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getCompLength(string s, int count)
{
    string compStr = "";    
    while (count < s.size())
    {
        string word = s.substr(0, count);        
        int compCount = 0;        
        while (0 == s.find(word))
        {
            s = s.substr(word.size(), s.size() - word.size());
            ++compCount;
        }
        
        if (compCount < 1)
        {
            word = s[0];            
            s = s.substr(1, s.size() - 1);            
        }
        
        if (compCount > 1)
        {
            compStr += to_string(compCount);
        }
        compStr += word;
    }
    compStr += s;
    return compStr.length();
}

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= 5000; ++i)
    {
        answer = min(getCompLength(s, i), answer);
    }    
    return answer;
}