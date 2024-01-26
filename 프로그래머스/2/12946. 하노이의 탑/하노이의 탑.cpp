#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int s, int e, int n)
{
    if (n <= 1)
    {
        vector<int> se{s, e};
        answer.push_back(se);
        return;
    }
        
    int m = 6 - s - e;    
    --n;

    hanoi(s, m, n);
    hanoi(s, e, 1);
    hanoi(m, e, n);    
}

vector<vector<int>> solution(int n) 
{
    hanoi(1, 3, n);
    return answer;
}