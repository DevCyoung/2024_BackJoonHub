#include <string>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int solution(int x, int y, int n) 
{
    int answer = -1;
    bool visited[1000001] = {false, };
    int distance[1000001] = {0, };
    queue<int> q;
    q.push(x);
    
    while (!q.empty())
    {
        int nx = q.front();
        q.pop();
        
        if (nx == y)
        {
            answer = distance[nx];
            break;
        }
        else if (nx > y)
        {
            continue;
        }
        int arr[3] = {nx + n, nx * 2, nx * 3};
        
        for (int i = 0; i < 3; ++i)
        {
            if (arr[i] > y)
            {
                continue;
            }
            else if (visited[arr[i]])
            {
                continue;
            }

            visited[arr[i]] = true;
            distance[arr[i]] = distance[nx] + 1;
            q.push(arr[i]);
        }
    }
    
    
    return answer;
}