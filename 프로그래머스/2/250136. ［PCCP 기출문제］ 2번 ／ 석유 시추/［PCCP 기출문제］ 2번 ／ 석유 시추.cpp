#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

struct tPos
{
    int x;
    int y;
};

bool    visited[500][500];
int     hole[500];

void bfs(int x, int y, const vector<vector<int>>& land)
{      
    queue<tPos> bfs;    
    set<int> holeCheck;
    int     dx[4] = {0, 1, 0, -1};
    int     dy[4] = {1, 0, -1, 0};                
    int     count = 1;

    bfs.push({x, y});
    visited[y][x] = true;    
    holeCheck.insert(x);
    
    while(!bfs.empty())
    {
        tPos pos = bfs.front();
        bfs.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nx = pos.x + dx[i];
            int ny = pos.y + dy[i];
            
            if (nx < 0 || nx >= land[0].size())
            {
                continue;
            }
            else if (ny < 0 || ny >= land.size())
            {
                continue;
            }
            else if (land[ny][nx] == 0)
            {
                continue;
            }
            else if (visited[ny][nx])
            {
                continue;
            }
            
            visited[ny][nx] = true;
            bfs.push({nx, ny});
            holeCheck.insert(nx);            
            ++count;
        }
    }
    
    for (int item : holeCheck)
    {
        hole[item] += count;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    memset(visited, 0, sizeof(visited));
    memset(hole, 0, sizeof(hole));
    
    for (int y = 0; y < land.size(); ++y)
    {
        for (int x = 0; x < land[y].size(); ++x)
        {
            if (visited[y][x] || land[y][x] == 0)
            {
                continue;
            }
            
            bfs(x, y, land);
        }
    }
    
    for (int i = 0; i < 500; ++i)
    {
        if (answer < hole[i])
        {
            answer = hole[i];
        }
    }
    
    return answer;
}