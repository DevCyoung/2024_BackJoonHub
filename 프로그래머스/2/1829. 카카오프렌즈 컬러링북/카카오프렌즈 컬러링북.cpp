#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

struct tPos
{
    int x;
    int y;    
};

bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(tPos pos, vector<vector<int>>& picture)
{
    vector<tPos> bfs;
    
    bfs.push_back(pos);
    int size = 0;
    
    while (!bfs.empty())
    {
        tPos pos = bfs.back();
        bfs.pop_back();            
        for (int i = 0; i < 4; ++i)
        {
            int nx = dx[i] + pos.x;
            int ny = dy[i] + pos.y;
            
            if (nx < 0 || nx >= picture[0].size())
            {
                continue;
            }
            else if (ny < 0 || ny >= picture.size())
            {
                continue;
            }
            else if (picture[ny][nx] == 0)
            {
                continue;
            }            
            else if (picture[ny][nx] != picture[pos.y][pos.x])
            {
                continue;
            }
            else if (visited[ny][nx])
            {
                continue;
            }
            
            ++size;
            tPos newPos = {nx, ny};
            visited[ny][nx] = true;
            bfs.push_back(newPos);
        }
        
        
    }
    
    return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    vector<int> answer;        
    memset(visited, 0, sizeof(visited));    
    
    int count = 0;
    int maxSize = 0;
    
    for (int i = 0; i < picture.size(); ++i)
    {
        for (int j = 0; j < picture[i].size(); ++j)
        {
            if (picture[i][j] == 0)
            {
                continue;
            }
            else if (visited[i][j])
            {
                continue;
            }
            
            tPos pos = {j, i};
            int temp = bfs(pos, picture);
            if (maxSize < temp)
            {
                maxSize = temp;
            }
            
            ++count;
        }
    }
    answer.push_back(count);
    answer.push_back(maxSize);
    return answer;
}