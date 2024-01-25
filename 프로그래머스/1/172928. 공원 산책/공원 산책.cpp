#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int x, y = 0;
    int w = park[0].size();
    int h = park.size();

    for (int i = 0; i < park.size(); ++i)
    {
        for (int j = 0; j < park[i].size(); ++j)
        {
            if ('S' == park[i][j])
            {
                x = j;
                y = i;
            }
        }
    }

    for (string rout : routes)
    {
        int dx = 0;
        int dy = 0;
        int n = rout[2] - '0';

        switch (rout[0])
        {
        case 'N':
            dy = -1;
            break;
        case 'S':
            dy =  1;
            break;
        case 'W':
            dx = -1;
            break;
        case 'E':
            dx =  1;
            break;
        }

        int nx = x + dx * n;
        int ny = y + dy * n;

        if (nx < 0 || nx >= w || ny < 0 || ny >= h)
        {
            continue;
        }

        bool flag = false;
        for (int i = x; i != nx + dx; i += dx)
        {
            if (park[ny][i] == 'X')
            {
                flag = true;
                break;
            }
        }

        for (int i = y; i != ny + dy; i += dy)
        {
            if (park[i][nx] == 'X')
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            continue;
        }

        x = nx;
        y = ny;

    }

    answer.push_back(y);
    answer.push_back(x);

    return answer;
}
