#include <string>
#include <vector>
#include <iostream>

using namespace std;

void getBalance(const string& w, string* u, string* v)
{
    //u
    int i = 0;
    int balance = 0;
    while (i < w.size())
    {
        if (w[i] == '(')
        {
            ++balance;
        }
        else if (w[i] == ')')
        {
            --balance;
        }        
        *u += w[i];
        ++i;
        if (balance == 0)
        {
            break;
        }
    }
    
    for (; i < w.size(); ++i)
    {
        *v += w[i];
    }
}

bool isPerfactP(const string& parentheses)
{
    int balance = 0;
    for (char item : parentheses)
    {
        if (item == '(')
        {
            ++balance;
        }
        else if (item == ')')
        {
            --balance;
        }
        
        if (balance < 0)
        {
            break;
        }        
    }
    
    return balance == 0;
}

string recvUV(string p)
{
    //1
    if (p.empty())
    {
        return "";
    }
    
    //2
    string u = "";
    string v = "";    
    getBalance(p, &u, &v);
    
    //3
    if (isPerfactP(u))
    {
        //3 - 1
        u += recvUV(v);
    }
    //4
    else
    {
        // 4- 1
        string np(1, '(');
        np += recvUV(v);
        np += ')';
        
        for (int i = 1; i < u.size() - 1; ++i)
        {
            if (u[i] == '(')
            {
                np += ')';
            }
            else
            {
                np += '(';
            }
        }
        
        u = np;
    }
    
    return u;
}

string solution(string p) {
    string answer = recvUV(p);    
    //string u = recvUV(p);
    //std::cout << u << " $ " << v << std::endl;
    
    return answer;
}