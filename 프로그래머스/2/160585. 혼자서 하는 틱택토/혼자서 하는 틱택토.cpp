#include <string>
#include <vector>
#include <iostream>

using namespace std;

short wintable[8]
{
    0b00000000111000000,
    0b00000000000111000,
    0b00000000000000111,
    0b00000000100100100,
    0b00000000010010010,
    0b00000000001001001,
    0b00000000100010001,
    0b00000000001010100    
};

int solution(vector<string> board) {
    short o = 0;
    short x = 0;
    short oCount = 0;
    short xCount = 0;
    
    short pos = 8;    
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].length(); ++j)
        {
            if (board[i][j] == 'O')
            {
                o |= (1 << pos);
                ++oCount;
            }
            else if (board[i][j] == 'X')
            {
                x |= (1 << pos);
                ++xCount;
            }
            --pos;
        }
    }
    
    //승패판단
    short oWinCount = 0;
    short xWinCount = 0;
    for (int i = 0; i < 8; ++i)
    {        
        if ((wintable[i] & o) == wintable[i])
        {           
            ++oWinCount;
        }
        else if ((wintable[i] & x) == wintable[i])
        {
            ++xWinCount;
        }        
    }
    
    if (oWinCount == 1 && oWinCount == xWinCount)
    {
        return 0;
    }
    else if (oCount - xCount != 0 && oCount - xCount != 1)
    {
        return 0;
    }
    else if (oWinCount && !(oCount - xCount == 1))
    {
        return 0;
    }
    else if (xWinCount && oCount != xCount)
    {
        return 0;
    }
    
    return 1;
}