#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int binaryTrans(const string& s, string* outBinary)
{
    int ZCount = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if ('0' == s[i])
        {
            ++ZCount;
        }
    }
    
    int oneCount = s.size() - ZCount;
    
    while (oneCount)
    {
        if (oneCount % 2)
        {
            *outBinary += '1';
        }        
        else
        {
            *outBinary += '0';
        }                
        oneCount /= 2;
    }    
    
    reverse(outBinary->begin(), outBinary->end());    
    
    return ZCount;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int delZCount = 0;
    int binCount = 0;
    
    string temp;
    
    temp.reserve(200000);
    
    while (1 != s.size())
    {
        delZCount += binaryTrans(s, &temp);        
        s = temp;
        temp.clear();
        ++binCount;
    }

    answer.push_back(binCount);
    answer.push_back(delZCount);
    return answer;
}