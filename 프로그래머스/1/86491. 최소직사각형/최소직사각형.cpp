#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int w = 0;
    int h = 0;
    for (const vector<int>& size : sizes)
    {
        w = max(w, min(size[0], size[1]));
        h = max(h, max(size[0], size[1]));
    }    
    return w * h;
}