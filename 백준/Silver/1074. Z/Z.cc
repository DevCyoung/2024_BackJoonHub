#include <iostream>

int zSearch(int N, int start, int r, int c)
{    
    if (N == 0)
    {
        return start;
    }
    
    int scale = 1 << N;
    int nextStep = (scale * scale) / 4;

    if (r < scale / 2 && c < scale / 2) //left up
    {

    }
    else if (r < scale / 2 && c >= scale / 2) //right up
    {
        start += nextStep;
        c -= scale / 2;
    }
    else if (r >= scale / 2 && c < scale / 2) // left down
    {
        start += nextStep * 2;
        r -= scale / 2;
    }
    else // right down
    {
        start += nextStep * 3;
        c -= scale / 2;
        r -= scale / 2;
    }

    return zSearch(N - 1, start, r, c);

}

int main()
{
    int N, r, c;

    std::cin >> N >> r >> c;
    int visit = zSearch(N, 0, r, c);
    std::cout << visit << std::endl;

    return 0;
}