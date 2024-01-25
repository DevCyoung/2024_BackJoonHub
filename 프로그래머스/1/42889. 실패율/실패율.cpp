#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct tFaile
{
    int stage;
    float failure;
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    int arr[501] = { 0, };
    for (int i = 0; i < stages.size(); ++i)
    {
        ++arr[stages[i]];
    }

    vector<tFaile> f;
    int count = stages.size();
    for (int i = 1; i < N + 1; ++i)
    {
        f.push_back({ i, (float)arr[i] / (float)count });        
        count -= arr[i];
    }


    for (int i = 0; i < f.size() - 1; ++i)
    {
        for (int j = i + 1; j > 0; --j)
        {
            if (f[j - 1].failure < f[j].failure)
            {
                tFaile temp = f[j - 1];
                f[j - 1] = f[j];
                f[j]  = temp;
            }
        }
    }

    for (int i = 0; i < f.size(); ++i)
    {
        answer.push_back(f[i].stage);
    }

    return answer;
}
