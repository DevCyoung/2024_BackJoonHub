#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {    
    int answer = 0;
    int giftPoint[50] = {0,};        
    int arr[50][50];        
    map<string, int> table;
    
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 50; ++j)
        {
            arr[i][j] = 0;
        }
    }
    
    for (const string& item : gifts)
    {        
        map<string,int>::iterator iter = table.find(item);
        if (iter == table.end())
        {
            table[item] = 1;
        }
        else
        {
            ++iter->second;
        }     
    }
    
    for (int i = 0; i < friends.size(); ++i)
    {
        for (int j = 0; j < friends.size(); ++j)
        {
            if (i == j)
            {
                continue;
            }
            
            string str = friends[i];
            str += " ";
            str +=  friends[j];
            map<string, int>::iterator iter = table.find(str);
            if (iter != table.end())
            {
                arr[i][j] = iter->second;
                giftPoint[i] += arr[i][j];
                giftPoint[j] -= arr[i][j];
            }            
        }
    }
    
    for (int i = 0; i < friends.size(); ++i)
    {
        int temp = 0;
        for (int j = 0; j < friends.size(); ++j)
        {
            if (i == j)
            {
                continue;
            }
                                
            if (arr[j][i] < arr[i][j])
            {
                ++temp;
            }
            else if (arr[j][i]  == arr[i][j] && giftPoint[j] < giftPoint[i])
            {
                ++temp;
            }
        }
        
        if (answer < temp)
        {
            answer = temp;
        }
    }    
    return answer;
}