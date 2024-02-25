#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long sd = (long long)d * (long long)d;    
    long long aNum = 0;
    for (long long i = 0; i * i <= sd; i += k)
        aNum = i;
    for (long long i = 0; i * i <= sd; i += k)
    {
        while (sd < i * i + aNum * aNum)        
            aNum -= k;        
        answer += aNum / k + 1;
    }    
    return answer;
}