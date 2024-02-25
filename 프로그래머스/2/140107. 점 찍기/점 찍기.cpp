#include <string>
#include <vector>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long sd = (long long)d * (long long)d;    
    long long anums = 0;

    for (long long i = 0; i * i <= sd; i += k)
        anums = i;    
    for (long long i = 0; i * i <= sd; i+=k)
    {
        while (sd < i * i + anums * anums)
            anums -= k;
        answer += anums / k + 1;
    }

    return answer;
}