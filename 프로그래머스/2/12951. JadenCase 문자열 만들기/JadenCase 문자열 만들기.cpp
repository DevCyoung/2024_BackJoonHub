#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    
    answer.reserve(s.size());
    
    bool flag = true;
    for (char item : s)
    {
        if (item == ' ')
        {
            flag = true;
        }
        else if (std::isdigit(item))
        {
            flag = false;
        }
        else if (flag)
        {
            item &= ~(1<<5);
            flag = false;
        }
        else
        {
            item |= (1<<5);
        }
        
        answer += item;
    }
    
    return answer;
}