#include <string>
#include <vector>

using namespace std;

struct tQ
{
    int zero;
    int one;
};

tQ comp(int x, int y, int size, const vector<vector<int>>& arr)
{
    if (size == 1)
    {        
        if (arr[y][x] == 0)
        {
            return {1, 0};
        }

        return {0, 1};
    }        
    
    tQ q1 = comp(x            , y           , size  / 2, arr);
    tQ q2 = comp(x + size / 2 , y           , size  / 2, arr);
    tQ q3 = comp(x,             y + size / 2, size  / 2, arr);
    tQ q4 = comp(x + size / 2 , y + size / 2, size  / 2, arr);
    
    tQ sumQ = {};
    sumQ.zero = q1.zero + q2.zero + q3.zero + q4.zero;
    sumQ.one = q1.one + q2.one + q3.one + q4.one;

    if (sumQ.zero == 0)
    {
        sumQ.one = 1;
    }
    if (sumQ.one == 0)
    {
        sumQ.zero = 1;
    }    

    return sumQ;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    tQ q = comp(0, 0, arr.size(), arr);    
    answer.push_back(q.zero);
    answer.push_back(q.one);
    return answer;
}