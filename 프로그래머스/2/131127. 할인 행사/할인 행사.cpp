#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> check;
    
    for (int i = 0; i <= discount.size() -10; ++i)
    {
        check.clear();
        for (int j = 0; j < 10; ++j)
        {
            ++check[discount[i + j]];
        }
        
        bool flag = true;
        for (int j = 0; j < number.size(); ++j)
        {
            if (number[j] > check[want[j]])
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            ++answer;
        }
        
    }
    
    return answer;
}