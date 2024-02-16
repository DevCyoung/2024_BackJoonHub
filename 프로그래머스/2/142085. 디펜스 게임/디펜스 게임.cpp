#include <string>
#include <vector>
#include  <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemys) {
    int answer = k;        
    long long sum = 0;
    priority_queue<int, std::vector<int>, std::greater<int>> q;

    for (int i = 0; i < enemys.size(); ++i)
    {        
        if (q.size() < k)
        {
            q.push(enemys[i]);
        }
        else if (q.top() <= enemys[i])
        {
            sum += q.top();
            q.pop();
            q.push(enemys[i]);
        }
        else
        {
            sum += enemys[i];
        }
        
        if (sum <= n)
        {
            answer = i + 1;
        }
        else
        {
            break;
        }     
    }
    
    
    return answer;
}