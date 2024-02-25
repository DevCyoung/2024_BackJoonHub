#include <string>
#include <vector>

using namespace std;

bool isSafe(vector<string> place)
{
    int dx[4] = {0, 1,  0, -1};
    int dy[4] = {1, 0, -1,  0};
    for (int y = 0; y < 5; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            if (place[y][x] == 'P')
            {
                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if (nx <0 || ny < 0 || nx >=5 || ny >= 5 || place[ny][nx] == 'X')
                        continue;
                    if (place[ny][nx] == 'B' || place[ny][nx] == 'P')
                        return false;
                    place[ny][nx] = 'B';
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (vector<string> place : places)
    {
        answer.push_back(isSafe(place));
    }
    return answer;
}