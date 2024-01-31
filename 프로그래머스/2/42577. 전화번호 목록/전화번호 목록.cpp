#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;
    
    map<string, bool> map;
    
    for (const string& phoneNum : phoneBook)
    {
        map[phoneNum] = true;
    }        
    
    for (const string& phoneNum : phoneBook)
    {
        string tempNum;
        tempNum.reserve(phoneNum.size());
        
        for (int i = 0; i < phoneNum.size() - 1; ++i)
        {
            tempNum += phoneNum[i];
            if (map[tempNum])
            {
                return false;
            }
        }
    }
    
    return true;
}