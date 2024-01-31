#include <iostream>
#include<string>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    string str;
    str.reserve(s.size());
    
    for (char item : s)
    {
        str += item;

        while (str.size() > 1 && str[str.size() - 1] == str[str.size() - 2])
        {
            str.pop_back();
            str.pop_back();
        }        
    }

    if (str.size() == 0)
    {
        answer = 1;
    }
    
    return answer;
}