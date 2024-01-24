#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
        
    string str = "";
    
    for (char item : myStr)
    {
        if (item != 'a' && item != 'b' && item != 'c')
        {            
            str += item;
        }
        else if (!str.empty())
        {
            answer.push_back(str);
            str = "";
        }        
    }
    
    if (str.empty())
    {
        answer.push_back("EMPTY");
    }
    else
    {
        answer.push_back(str);
    }
    
    return answer;
}