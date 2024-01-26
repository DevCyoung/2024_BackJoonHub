#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
        
    while (n)
    {
        --n;
        answer += "124"[n % 3];
        n /= 3;        
    }
    
    std::reverse(answer.begin(), answer.end());
        
    return answer;
}