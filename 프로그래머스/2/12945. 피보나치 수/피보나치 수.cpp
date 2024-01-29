#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    unsigned long long answer = 0;
    unsigned long long  a = 0;
    unsigned long long  b = 1;

    for (int i = 2; i <= n; ++i)
    {
        answer = (a + b) % 1234567;        
        a = b;
        b = answer;
    }

    return (int)(answer % 1234567);
}