#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
using namespace std;

int solution(int N, vector<vector<int> > roads, int K) {
    int     answer          = 0;
    int     vs[51][51]      = {0,};
    int     distance[51]    = {0,};
    bool    visited[51]     = {0,};
    
    memset(vs, -1, sizeof(vs));
    std::fill(std::begin(distance),std::end(distance), INT_MAX);
    
    for (vector<int>& r : roads)
    {        
        int s = r[0];
        int e = r[1];
        int d = r[2];
        
        if (vs[s][e] != -1 && vs[s][e] < d)
        {
            continue;
        }
        if (vs[e][s] != -1 && vs[e][s] < d)
        {
            continue;
        }
        
        vs[s][e] = d;
        vs[e][s] = d;
    }
    
    distance[1] = 0;
    
    while (1)
    {
        int closet = INT_MAX;
        int n = -1;        
        for (int i = 1; i <= N; ++i)
        {
            if (visited[i])
            {
                continue;
            }
            if (distance[i] == INT_MAX || distance[i] >= closet)
            {
                continue;
            }
            
            closet = distance[i];
            n = i;
        }
        
        if (n == -1)
        {
            break;
        }
        
        visited[n] = true;
        
        for (int i = 1; i <= N; ++i)
        {
            if (vs[n][i] == -1)
            {
                continue;
            }
            else if (visited[i])
            {
                continue;
            }
            
            int nDist = distance[n] + vs[n][i];
            
            if (nDist < distance[i])
            {
                 distance[i] = nDist;                
            }
        } 
        
    }
    
    for (int i = 1; i <= N; ++i)
    {
        if (distance[i] <= K)
        {
            ++answer;
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
          std::cout << vs[i][j] << "\t";
        }
        std::cout << std::endl;
        //std::cout << "node : " << i << " " << distance[i] << std::endl;
    }

    return answer;
}
