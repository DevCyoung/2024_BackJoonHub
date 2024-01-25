#include <string>
#include <vector>

using namespace std;

bool IsBab(string bab)
{    
    //strstr
    string words[4] = {"aya", "ye", "woo", "ma"};
    
    string prev = "";
    while (bab != "")
    {
        bool flag = true;
        for (string word : words)
        {
            string::size_type n = bab.find(word);
            if (n == 0 && prev != word)
            {
                bab = bab.substr(word.size(), bab.size() - word.size());
                prev = word;
                flag = false;                
            }            
        }
        
        if (flag)
        {
            return false;
        }
    }
    
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;    
    for (string bab : babbling)
    {
        if (IsBab(bab))
        {
            ++answer;
        }
    }
    return answer;
}