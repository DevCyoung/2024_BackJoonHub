//두 번째 줄에는 행성계의 개수
//n이 주어지며, 세 번째 줄부터 n줄에 걸쳐 행성계의 중점과 반지름 (cx, cy, r)이 주어진다.

#include <iostream>
#include <cmath>

int is_inner(int x, int y, int cx, int cy, int r)
{
    float distance;

    distance = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y));
    if (distance <= r)
        return 1;
    return 0;
}

int main(void)
{
    int T;
    int N;
    int x1, y1, x2, y2;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cin >> N;
        int s_cnt = 0;
        int e_cnt = 0;
        int two_inner = 0;
        for (int j = 0; j < N; j++)
        {
            int cx, cy, r;
            int checks = 0;
            int checke = 0;
            std::cin >> cx >> cy >> r;
            checks = is_inner(x1, y1, cx, cy, r);
            checke = is_inner(x2, y2, cx, cy, r);
            if (checks == 1)
			{
				++s_cnt;
			}
            if (checke == 1)
			{
                ++e_cnt;
			}
            if (checks && checke)
			{
                ++two_inner;
			}
            checks = 0;
            checke = 0;
        }
        std::cout << (s_cnt + e_cnt) - (2 * two_inner) << std::endl;
    }
    return 0;
}