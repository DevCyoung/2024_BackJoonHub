#include <iostream>

//x y 자리가 공격 가능한 자리인가?
bool isAttackable(const int x, const int y, const int (&arr)[13])
{
    //세로
    for (int ny = 0; ny < y; ++ny)
    {
        if (x == arr[ny])
        {   
            return false;
        }
    }
    
    //-> 대각선
    for (int ny = 0; ny < y; ++ny)
    {
        if (ny - arr[ny] == y - x)
        {
            return false;
        }
    }
    
    //<- 대각선
    for (int ny = 0; ny < y; ++ny)
    {
        if (ny + arr[ny] == y + x)
        {
            return false;
        }
    }
    return true;
}

int nQuene(int y, const int n, int (&arr)[13])
{
    if (y == n)
    {
        return 1;
    }

    int ret = 0;
    
    for (int x = 0; x < n; ++x)
    {        
        //놓을수있는지 검사
        if (!isAttackable(x, y, arr))
        {
            continue;
        }
        
        arr[y] = x;
        ret += nQuene(y + 1, n, arr);
    }
    
    return ret;
}

int solution(int n) {
    
    int arr[13] = {0,};
    int answer = nQuene(0, n, arr);
    
    return answer;
}