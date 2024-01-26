#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> scores) {
    vector<int> answer;
    vector<int> insert;
    for (int i = 0; i < scores.size(); ++i)
    {
        int score = scores[i];
        insert.push_back(score);
        for (int j = insert.size() - 1; j > 0; --j)
        {
            if (insert[j - 1] < insert[j])
            {
                int temp = insert[j - 1];
                insert[j - 1] = insert[j];
                insert[j] = temp;
            }
            else
            {
                break;
            }
        }
        
        if (insert.size() < k)
        {
            answer.push_back(insert.back());
        }
        else
        {
            answer.push_back(insert[k - 1]);
        }
    }    
    return answer;
}