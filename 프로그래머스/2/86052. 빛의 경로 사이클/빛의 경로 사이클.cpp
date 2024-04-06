#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3

#define S       0
#define L       1
#define R       2

bool visited[500][500][4];

                // S               L              R
                // U  D   L  R     U  D  L   R    U   D   L   R
int  dx[3][4] = {{ 0, 0, -1, 1}, {-1, 1, 0,  0}, {1, -1,  0,  0}};
int  dy[3][4] = {{-1, 1,  0, 0}, { 0, 0, 1, -1}, {0,  0, -1,  1}};

int  nextdir[3][4] = {{    UP,  DOWN, LEFT, RIGHT}, 
                      {  LEFT, RIGHT, DOWN,    UP}, 
                      { RIGHT,  LEFT,   UP,  DOWN}};

struct tLight
{
    int dir;
    int x;
    int y;
};

tLight get_next_light(int x, int y, int dir, char turndir, int width, int height)
{
    int turn = S;
    if (turndir == 'R')
    {
        turn = R;
    }
    else if (turndir == 'L')
    {
        turn = L;
    }
    
    int nx  = x + dx[turn][dir];
    int ny  = y + dy[turn][dir];
    if (nx < 0)
    {
        nx = width - 1;
    }
    else if (nx >= width)
    {
        nx = 0;
    }
    
    if (ny < 0)
    {
        ny = height - 1;
    }
    else if (ny >= height)
    {
        ny = 0;
    }
    
    return {nextdir[turn][dir], nx, ny};
}

int get_cycle_count(const vector<string>& grid, const tLight& light, const int width, const int height)
{    
    int ret = 0;
    tLight l = light;
    visited[l.y][l.x][l.dir] = true;    
    while (1)
    {        
        tLight nl = get_next_light(l.x, l.y, l.dir, grid[l.y][l.x], width, height);               
        
        if (light.dir == nl.dir && light.x == nl.x && light.y == nl.y)
        {
            break;
        }
        else if (visited[nl.y][nl.x][nl.dir])
        {
            return -1;
        }
        
        visited[nl.y][nl.x][nl.dir] = true;
        l = nl;        
        ++ret;
    }   
    return ret + 1;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    memset(visited, false, sizeof(visited));
    
    int height = grid.size();
    int width = grid[0].length();
    
    for (int y = 0; y < grid.size(); ++y)
    {
        for (int x = 0; x < grid[y].length(); ++x)
        {
            for (int dir = 0; dir < 4; ++dir)
            {
                if (visited[y][x][dir])
                {
                    continue;
                }
                
                tLight light = {dir, x, y};
                int count = get_cycle_count(grid, light, width, height);                        
                answer.push_back(count);
            }
        }
    }
    
    std::sort(answer.begin(), answer.end());
    return answer;
}