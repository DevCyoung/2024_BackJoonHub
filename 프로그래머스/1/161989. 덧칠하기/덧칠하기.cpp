#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int answer = 0;
    
    //한칸씩 이동한다
    //영역을 발견한다
    //길이만큼 칠한다
    //if 길이만큼 점프하려는데 size 넘어간다면....
    //size순회하며 하나라도있으면 ++ 하고 종료한다.
    
    int head = 0; //왼쪽끝 롤러위치    
    std::reverse(section.begin(), section.end());
    while (head < n && !section.empty() )
    {        
        //칠해야하는곳
        int wall = section.back() - 1;        
        if (wall < head)
        {           
            section.pop_back();
            continue;
        }
        
        //헤드옮기기        
        head = wall + m;                
        ++answer;            
    }
    
    
    return answer;
}