#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//"dxccxbbbxxaaaa" ["aaaa", "bbb", "cc", "d"]
vector<string> split(const string src, const char c)
{
    vector<string> answer;
    string str = "";
    
    for (char item : src)
    {
        if (item != c)
        {
            str += item;   
        }   
        else if (!str.empty())
        {
            answer.push_back(str);
            str = "";
        }
    }
    
    if (!str.empty())
    {
        answer.push_back(str);        
    }
    
    return answer;
}

int compare(const string& a, const string& b)
{
 return a.compare(b);
}

vector<string> InserSort(const vector<string>& src)
{
    vector<string> answer(src.cbegin(), src.cend());    
    
    for (int i = 1; i < answer.size(); ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (0 < compare(answer[j - 1], answer[j]))
            {
                string temp = answer[j - 1];
                answer[j - 1] = answer[j];
                answer[j] = temp;
            }
            else
            {
                break;
            }
        }
    }
    
    return answer;
}

vector<string> solution(string myString) {
    vector<string> answer = split(myString, 'x');
    answer = InserSort(answer);    
    return answer;
}