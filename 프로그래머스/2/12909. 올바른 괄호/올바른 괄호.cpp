#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;    
    int stack = 0;
    
    for (char item : s)
    {
        if ( '(' == item)
        {
            ++stack;
        }
        else
        {
            --stack;
        }
        
        if (stack < 0)
        {
            answer = false;
            break;
        }
    }
    return stack == 0;
}