#include <string>
#include <vector>
#include  <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemys) {
    int answer = enemys.size() > k ? k : enemys.size();    
    priority_queue<int, std::vector<int>, std::greater<int>> q;

    for (int i = 0; i < k; ++i)
    {
        q.push(enemys[i]);
    }
    
    for (int i = k; i < enemys.size(); ++i)
    {        
        if (q.top() <= enemys[i])
        {
            n -= q.top();
            q.pop();
            q.push(enemys[i]);
        }
        else
        {
            n -= enemys[i];
        }
        
        if (n >= 0)
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