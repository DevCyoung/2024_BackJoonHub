#include <string>
#include <vector>
#include <cstring>

using namespace std;

//거리계산 distance 8과 9
// 1 = 0, 0
// 2 = 0, 1
// 3 = 0, 2
// 4 = 1, 0
// 5 = 1, 1
// 6 = 1, 2
// 7 = 2, 1
// 8 = 2, 2
// 9 = 2, 3
// 0 = 3, 2

//즉 판단은 가운데 버튼을 누를때만함

struct tPos
{
    int x;
    int y;
};


int distance(int hand, int dest)
{
    tPos posArr[30] = {0,};
    memset(posArr, 0, sizeof(posArr));
              
    int k = 1;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            posArr[k] = {i, j};
            k++;
        }
    }
    posArr[0] = {3, 1};
    int x = posArr[hand].x - posArr[dest].x;
    int y = posArr[hand].y - posArr[dest].y;
    
    x = x < 0 ? x * -1 : x;
    y = y < 0 ? y * -1 : y;

    return x + y;
}

string solution(vector<int> numbers, string hand) {
    
    //누가더 가까운가 2, 5, 8, 0 중에서...
    string answer;
    
    int lPos = 10;
    int RPos = 12;
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