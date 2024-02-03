#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;        
    int left = 0;
    int right = people.size() - 1;
    std::sort(people.begin(), people.end());
    
    while (left <= right)
    {
        int temp = limit;
        int i = 0;
        for (; i < 2 && temp - people[right] >= 0; ++i)
        {
            temp -= people[right];
            --right;
        }
        
        for (; i < 2 && temp - people[left] >= 0; ++i)
        {
            temp -= people[left];
            ++left;
        }

        ++answer;
    }
    
    return answer;
}