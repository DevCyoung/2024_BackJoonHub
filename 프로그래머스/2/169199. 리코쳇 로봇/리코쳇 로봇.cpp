#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

pair<int, int> get_end_pos(pair<int, int> start, pair<int, int> dir, const vector<string>& board)
{
    int x = start.first;
    int y = start.second;
    
    int width = board[0].length();
    int height = board.size();
    
    while (1)
    {                
        int nx = x + dir.first;
        int ny = y + dir.second;                
        
        if (nx < 0 || nx >= width || ny < 0 || ny >= height || board[ny][nx] == 'D' )
        {
            return {x, y};
        }
        
        x = nx;
        y = ny;
    }
}

int solution(vector<string> board) {        
    bool visited[100][100];
    int  distance[100][100];
    queue<pair<int,int>> q;
    memset(visited, false, sizeof(visited));
    memset(distance, 0, sizeof(distance));
    
    const int dx[4] = {0, 1,  0, -1};
    const int dy[4] = {1, 0, -1,  0};        
    
    pair<int, int> start;
    pair<int, int> end;    
    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board[y].length(); ++x)
        {
            if (board[y][x] == 'R')
            {
                start = {x, y};
            }
            else if (board[y][x] == 'G')
            {
                end = {x, y};
            }
        }
    }
    
    visited[start.second][start.first] = true;
    q.push(start);
    
    while (!q.empty())
    {
        const pair<int, int> pos =  q.front();
        q.pop();
        
        const int x = pos.first;
        const int y = pos.second;
    
        for (int i = 0; i < 4; ++i)
        {        
            const pair<int,int> npos = get_end_pos({x,y}, {dx[i], dy[i]}, board);            
            const int nx = npos.first;
            const int ny = npos.second;
            
            if (visited[ny][nx])
            {
                continue;
            }     
            
            visited[ny][nx]  = true;
            distance[ny][nx] = distance[y][x] + 1;            
            q.push({nx, ny});                    
        }
    }
    
    if (distance[end.second][end.first] == 0)
    {
        distance[end.second][end.first] = -1;
    }
    
    return distance[end.second][end.first];
}