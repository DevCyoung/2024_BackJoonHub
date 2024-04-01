#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_bit_on(vector<long long> (&pat)[21], long long n, long long pos)
{
    if (n == 1)
    {
        return pos != 3;
    }    
    if (pos <= pat[n][0])
    {  
    }
    else if (pos <= pat[n][0] << 1)
    {
        pos -= pat[n][0];
    }
    else if (pos <= (pat[n][0] << 1) + pat[n][1])
    {
        n = 2;
        pos = 3;
    }
    else if (pos <= pat[n][0] * 3 + pat[n][1])
    {
        pos -= (pat[n][0] << 1) + pat[n][1];
    }
    else
    {
        pos -= pat[n][0] * 3 + pat[n][1];
    }    
    return is_bit_on(pat, n - 1, pos);
}

int solution(int n, long long l, long long r) {
    int answer = 0;        
    vector<long long> pat[21];
    
    //ㅁ ㅁ 0 ㅁ ㅁ
    //pat[0] (ㅁ 하나당 길이)
    //pat[1] (0의 길이)    
    pat[1] = {1, 1};
    for (int i = 2; i < 21; ++i)
    {
        pat[i].resize(2);
        pat[i][0] = pat[i - 1][0] * 4 + pat[i - 1][1];
        pat[i][1] = pat[i - 1][1] * 5;        
    }
    
    for (long long i = l; i <= r; ++i)
    {
        if (is_bit_on(pat, n, i))
        {
            ++answer;
        }             
    }    
    return answer;
}