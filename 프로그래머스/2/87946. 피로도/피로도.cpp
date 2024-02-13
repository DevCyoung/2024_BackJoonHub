#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[8] = {false,};

void recv(int k, const vector<vector<int>>& dungeons, int count)
{       
    if (answer < count)
    {
        answer = count;
    }
    
    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (visited[i])
        {
            continue;
        }

        const vector<int>& temp = dungeons[i];        

        int nK = k;
        int nCount = count;
        if (temp[0] <= nK)
        {                        
            nK -= temp[1];
            ++nCount;
            
                    visited[i] = true;
        recv(nK, dungeons, nCount);
        visited[i] = false;        
        }             
        

    }
    
}

int solution(int k, vector<vector<int>> dungeons) {    
    recv(k, dungeons, 0);    
    return answer;
}