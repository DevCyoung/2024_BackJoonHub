#include <string>
#include <cctype>
#include <map>
#include <iostream>


using namespace std;

void insert2Words(map<string, int>& m, string& str)
{
    for (int i = 0; i < str.size() - 1; ++i)
    {
        string temp = "";        
        for (int j = 0; j < 2; ++j)
        {
            char c = str[i + j];
            if (std::isalpha(c))
            {
                c |= (1 << 5);
            }
            temp += c;
        }

        //std::cout << str << " "<< ":" << temp << " " <<  " : "<< temp[i] << isalpha(temp[i]) << std::endl;
        
        if (isalpha(temp[0]) && isalpha(temp[1]))
        {
            //std::cout << str << " "<< ":" << temp << std::endl;
            ++m[temp];
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    
    //FR FR FR FR FR NC CE CE
    //FR EN FD CE        
    
    //FR RA AN NC CE
    //FR RE EN NC CH
    
    map<string, int> map1;
    map<string, int> map2;
    map<string, int> map3;
    
    insert2Words(map1, str1);
    insert2Words(map2, str2);
    
    int sum = 0;
    int n = 0;

    map<string,int>::iterator iter1 = map1.begin();        
    for (; iter1 != map1.end(); ++iter1)
    {
        map<string,int>::iterator iter2 = map2.find(iter1->first);
        
        if (iter2 == map2.end())
        {
            map3[iter1->first] = iter1->second;            
        }
        else if (iter1->second < iter2->second)
        {
            map3[iter2->first] = iter2->second;
            n += iter1->second;
            std::cout << "iter1->second < iter2->second " << iter1->second << " < " << iter2->second 
                << " " << iter1->first <<" " << iter2->first << std::endl;
        }
        else
        {
            map3[iter1->first] = iter1->second;
            n += iter2->second;            
            std::cout << "iter1->second >= iter2->second " << iter1->second << " >= " << iter2->second 
                << " " << iter1->first <<" " << iter2->first << std::endl;
        }
        
    }
    
    map<string,int>::iterator iter2 = map2.begin();    
    for (; iter2 != map2.end(); ++iter2)
    {
        map<string,int>::iterator iter3 = map3.find(iter2->first);
        if (iter3 == map3.end())
        {
            map3[iter2->first] = iter2->second;            
        }
    }
    
    map<string,int>::iterator iter3 = map3.begin();    
    
    std::cout << map3.size() << std::endl;
    for (; iter3 != map3.end(); ++iter3)
    {
        sum += iter3->second;
        std::cout << iter3->first << " " << iter3->second << std::endl;
    }
    std::cout << "N " << n << std::endl;
    std::cout << "SUM " << sum << std::endl;
    std::cout << (int)((n / (float)sum) * 65536) << std::endl;
    //HA AN ND DS SH HA AK KE
    //SH HA AK KE H HA AN ND DS
    
    //2HA
    
    answer = (int)((n / (float)sum) * 65536);
    
    if (answer < 0)
    {
        answer = 65536;
    }
    
    return answer;
}