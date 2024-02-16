#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> temp;

    temp.resize(numbers.size());

    temp[numbers.size() - 1] = -1;
    for (int i = numbers.size() - 2; i >= 0; --i)
    {
        int idx = i + 1;
        while (idx != -1 && idx < numbers.size() && numbers[i] >= numbers[idx])
        {
            idx = temp[idx];
        }        

        if (numbers[i] < numbers[idx])
        {
            temp[i] = idx;
        }
        else
        {
            temp[i] = -1;
        }
    }

    for (int i = 0; i < temp.size(); ++i)
    {                
        if (temp[i] == -1)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(numbers[temp[i]]);
        }
    }
    std::cout << std::endl;

    return answer;
}