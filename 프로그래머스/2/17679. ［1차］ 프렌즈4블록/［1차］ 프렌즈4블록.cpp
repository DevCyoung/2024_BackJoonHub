#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool IsSame4Block(int x, int y, const vector<string>& board)
{    
    char target = board[y][x];
    return target == board[y + 1][x] && target == board[y][x + 1] && target == board[y + 1][x + 1];
}

int dropBolck(int m, int n, vector<string>& board)
{
    int answer = 0;
    bool visited[30][30] = {0,};

    for(int y = 0; y <= m - 2; ++y)
    {        
        for (int x = 0; x <= n - 2; ++x)
        {
            if (board[y][x] == 'X')
            {
                continue;
            }
            else if (IsSame4Block(x, y, board))
            {
                visited[y][x]         = true;
                visited[y][x + 1]     = true;
                visited[y + 1][x]     = true;
                visited[y + 1][x + 1] = true;
            }
        }
    }
                    
    for(int y = 0; y < m; ++y)
    {                        
        for (int x = 0; x < n; ++x)
        {
            if (visited[y][x])
            {
                board[y][x] = 'X';
                ++answer;
            }
        }
    }
    
    for(int x = 0; x < n; ++x)
    {        
        string drop = "";        
        for (int y = m -1; y >= 0; --y)
        {
            if (board[y][x] != 'X')
            {
                drop += board[y][x];
            }            
        }
        
        while (drop.size() < m)
        {
            drop += 'X';
        }
        
        std::reverse(drop.begin(), drop.end());
        
        for (int y = 0; y < m; ++y)
        {
            board[y][x] = drop[y];
        }
        
    }    
    return answer;
}

int solution(int m, int n, vector<string> board) 
{    
    int answer = 0;
    int temp = 0;
    do
    {
        temp = dropBolck(m, n, board);
        answer += temp;
    } while (temp);
    
    return answer;
}