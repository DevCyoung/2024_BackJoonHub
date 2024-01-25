#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct tPos
{
    int x;
    int y;
};

tPos posArr[12] = {
    {3, 1},                  // 0
    {0, 0}, {0, 1}, {0, 2},  // 1 2 3
    {1, 0}, {1, 1}, {1, 2},  // 4 5 6
    {2, 0}, {2, 1}, {2, 2},  // 7 8 9
    {3, 0},         {3, 2}   // *   #
};

int distance(int hand, int dest)
{                      
    int x = posArr[hand].x - posArr[dest].x;
    int y = posArr[hand].y - posArr[dest].y;
    
    x = x < 0 ? x * -1 : x;
    y = y < 0 ? y * -1 : y;
    
    return x + y;
}

string solution(vector<int> numbers, string hand) {
    string answer;
    
    int lPos = 10;
    int RPos = 11;
    for (int num : numbers)
    {
        if (num == 1 || num == 4 || num == 7)
        {
            lPos = num;
            answer += "L";            
        }
        else if (num == 3 || num == 6 || num == 9)
        {
            RPos = num;
            answer += "R";
        }
        else if (distance(lPos, num) < distance(RPos, num))
        {
            lPos = num;
            answer += "L";   
        }
        else if (distance(RPos, num) < distance(lPos, num))
        {
            RPos = num;
            answer += "R";
        }
        else if (hand == "left")
        {
            lPos = num;
            answer += "L"; 
        }
        else
        {
            RPos = num;
            answer += "R";
        }
    }
    
    return answer;
}