#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};    
    string pickColor = board[h][w];    
    
    for (int k = 0; k < 4; k++)
    {
        int nx = dx[k] + w;
        int ny = dy[k] + h;
                
        if (nx < 0 || nx >= board[h].size())
        {
            continue;
        }
        else if (ny < 0 || ny >= board.size())
        {
            continue;
        }
        if (pickColor == board[ny][nx])
        {
            ++answer;
        }
    }
    
    return answer;
}