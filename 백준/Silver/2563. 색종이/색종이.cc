#include <iostream>

int main()
{
    bool rect[101][101] = { 0, };

    int cnt;

    std::cin >> cnt;

    for (int i = 0; i < cnt; ++i)
    {
        int x, y;

        std::cin >> x >> y;

        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                rect[x + j][y + k] = true;
            }            
        }
    }

    int result = 0;

    for (int i = 1; i < 101; ++i)
    {
        for (int j = 1; j < 101; ++j)
        {
            if (rect[i][j])
            {
                ++result;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}