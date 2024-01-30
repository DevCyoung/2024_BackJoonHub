#include <string>
#include <vector>
#include <iostream>
using namespace std;

int num(int a, int b)
{        
    if (a > b)
    {
        int temp  = a;
        a = b;
        b = temp;
    }
    
    while (a)
    {
        int temp = a;
        a = b % a;
        b = temp;
        
    }
    
    return b;
}

int solution(vector<int> arr) {    
    
    int answer = arr[0];    
    for (int i = 1; i < arr.size(); ++i)
    {     
        int m = num(answer, arr[i]);
        answer *= arr[i];
        answer /= m;
    }    
    return answer;
}