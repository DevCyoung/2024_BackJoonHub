#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool gPrimeArray[10000000];
int answer;

string removeAt(const string& str, int idx)
{
    string temp;
    temp.reserve(str.size());
    
    for (int i = 0; i < idx; ++i)
    {
        temp.push_back(str[i]);
    }
    
    for (int i = idx + 1; i < str.size(); ++i)
    {
        temp.push_back(str[i]);
    }
    
    return temp;
}

//1748
void recv(string str, string num)
{
    if (str.empty())
    {        
        return ;
    }

    for (int i = 0; i < str.size(); ++i)
    {        
        string newNum = num;
        newNum += str[i];
        
        int idx = std::atoi(newNum.c_str());
        if (gPrimeArray[idx])
        {
            ++answer;
            std::cout << "false";
            gPrimeArray[idx] = false;
        }
        
        std::cout << idx << std::endl;
        
        string temp = removeAt(str, i);
        recv(temp, newNum);
    }
}

int solution(string numbers) {
    answer = 0;
    //에라토스체    
    for (int i = 0; i < 10000000; ++i)
    {
        gPrimeArray[i] = true;
    }
    
    gPrimeArray[0] = false;
    gPrimeArray[1] = false;
    
    for (int i = 2; i * i < 10000000; ++i)
    {
        if (gPrimeArray[i])
        {
            for (int j = i *  i; j  < 10000000; j += i)
            {
                gPrimeArray[j] = false;
            }
        }
    }
    
    recv(numbers, "");
    return answer;
}