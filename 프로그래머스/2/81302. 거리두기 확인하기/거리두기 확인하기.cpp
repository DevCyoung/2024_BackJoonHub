#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool bfs(const int x, const int y, const vector<string>& place)
{
    int dx[4] = {0, 1,  0,  -1};
    int dy[4] = {1, 0, -1,   0};    
    bool visited[5][5];
    queue<pair<int,int>> q;
    
    q.push({x, y});
    memset(visited, false, sizeof(visited));            
    visited[y][x] = true;
    
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = pos.first  + dx[i];
            int ny = pos.second + dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[ny][nx])
                continue;
            else if (abs(nx - x) + abs(ny - y) > 2 || place[ny][nx] == 'X')
                continue;                        
            if (place[ny][nx] == 'P')
            {
                return false;
            }
            visited[ny][nx] = true;
            q.push({nx, ny});
        }
    }
    return true;
}
bool isSafe(vector<string> place)
{
    for (int y = 0; y < 5; ++y)
    {        
        for (int x = 0; x < 5; ++x)
        {
            if (place[y][x] != 'P')
                continue;
            if (false == bfs(x, y, place))
                return false;      
        }        
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (vector<string>& place : places)
        answer.push_back(isSafe(place));        
    return answer;
}