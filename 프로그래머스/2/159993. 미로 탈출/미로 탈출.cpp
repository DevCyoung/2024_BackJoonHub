#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
//레버로 갔다가 출구로가야함
//레버로까지 최단거리
//출구로까지최단거리

int get_short_dis(const vector<string>& maps, pair<int,int> start, pair<int,int> end)
{    
    bool visited[101][101];
    int  distance[101][101];
    int  dx[4]          = {0, 1,  0, -1};
    int  dy[4]          = {1, 0, -1,  0};
    const int  height   = maps.size();
    const int  width    = maps[0].size();
    std::memset(visited, false, sizeof(visited));    
    std::memset(distance, 0, sizeof(distance));
    
    visited[start.second][start.first] = true;
    
    queue<pair<int, int>> q;    
    q.push(start);
    
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        
        int x = pos.first;
        int y = pos.second;
        
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (ny < 0 || ny >= height)
            {
                continue;
            }
            else if (nx < 0 || nx >= width)
            {
                continue;
            }
            else if (visited[ny][nx])
            {
                continue;
            }
            else if (maps[ny][nx] == 'X')
            {
                continue;
            }
            
            visited[ny][nx] = true;
            distance[ny][nx] = distance[y][x] + 1;
            q.push({nx, ny});
        }        
    }
    
    return distance[end.second][end.first];
}

pair<int, int> get_pos(vector<string> maps, char c)
{
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] == c)
            {
                return {j, i};
            }
        }
    }
}

int solution(vector<string> maps) {    
    int answer = -1;
    
    pair<int, int> start = get_pos(maps, 'S');
    pair<int, int> lever  = get_pos(maps, 'L');
    pair<int, int> exit  = get_pos(maps, 'E');
    
    int s2l = get_short_dis(maps, start, lever);
    int l2e = get_short_dis(maps, lever, exit);
    
    if (s2l != 0 && l2e != 0)
    {
        answer = s2l + l2e;
    }
    
    return answer;
}
