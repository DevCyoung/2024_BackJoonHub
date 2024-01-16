#include <stdio.h>

int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1,  0,-1};

int DFS(int iArray[50][50], int x, int y, int x_size, int y_size)
{
    iArray[y][x] = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];
        if (nx < 0 || nx >= x_size)
            continue;
        if (ny < 0 || ny >= y_size)
            continue;
        if (iArray[ny][nx] == 0)
            continue;
        DFS(iArray, nx, ny, x_size, y_size);
    }
    return 1;
}

void clear(int iArray[50][50])
{
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            iArray[i][j] = 0;
        }
    }
}

int main()
{
    int T;
    int iArray[50][50];
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int N, M, K;
        int ret = 0;
        scanf("%d %d %d", &N, &M, &K);
        clear(iArray);
        for(int i = 0; i < K; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            iArray[y][x] = 1;
        }
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if (iArray[i][j] == 1)
                    ret += DFS(iArray, j, i, N, M);
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}