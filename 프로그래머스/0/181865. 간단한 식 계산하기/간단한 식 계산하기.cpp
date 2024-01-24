#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    
    char op = '\0';
    int num[2] = {0,};
    int idx = 0;
    for (char item : binomial)
    {
        if ('0' <= item && item <= '9')
        {
            num[idx] = 10 * num[idx] + item - '0';
        }
        else if (item == '+' || item == '-' || item == '*')
        {            
            op = item;
            ++idx;
        }
    }
    
    if (op == '+')
    {
        answer = num[0] + num[1];
    }
    else if (op == '-')
    {
        answer = num[0] - num[1];        
    }
    else
    {
        answer = num[0] * num[1];
    }
    
    return answer;
}