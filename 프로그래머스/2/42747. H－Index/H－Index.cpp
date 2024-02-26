#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//0 1 3 5 6
int solution(vector<int> citations) {    
    std::sort(citations.rbegin(), citations.rend());        
    for (int i = 0; i < citations.size(); ++i)    
        if (citations[i] <= i)
            return i;    
    return citations.size();
}
        
