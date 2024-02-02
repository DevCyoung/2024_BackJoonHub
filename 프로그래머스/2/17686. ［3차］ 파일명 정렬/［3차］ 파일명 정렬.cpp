#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

struct tFileName
{
    string head;
    string number;
    string tail;
    string fileName;
};

bool compare(const tFileName& a, const tFileName& b)
{
    if (a.head != b.head)
    {
        return a.head < b.head;
    }
    else if (std::atoi(a.number.c_str()) != std::atoi(b.number.c_str()))
    {
        return std::atoi(a.number.c_str()) < std::atoi(b.number.c_str());
    }
    
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tFileName> fileNames;
    
    fileNames.reserve(files.size());
    for (const string& file : files)
    {
        tFileName fileName = {};
        
        fileName.fileName = file;
        
        //head
        int i = 0;
        for (; i < file.size(); ++i)
        {
            if ('0' <= file[i] && file[i] <= '9')
            {
                break;
            }
            
            if (std::isalpha(file[i]))
            {                                
                fileName.head += (file[i] | (1 << 5));
            }   
            else
            {
                fileName.head += file[i];
            }
        }
        
        //number
        for (; i < file.size(); ++i)
        {
            if ('0' > file[i] || file[i] > '9')
            {
                break;
            }         
            
            fileName.number += file[i];
        }
        
        //taie
        for (; i < file.size(); ++i)
        {
            fileName.tail += file[i];
        }
        
        fileNames.push_back(fileName);
        
        std::cout << fileName.head << " " << fileName.number << " " << fileName.tail << " " << std::endl;
    }
    
    for (int i = 0; i < fileNames.size() - 1; ++i)
    {
        for (int j = 1 + i; j > 0; --j)
        {
            if (compare(fileNames[j], fileNames[j - 1]))
            {
                tFileName temp = fileNames[j - 1];
                fileNames[j - 1] = fileNames[j];
                fileNames[j] = temp;
            }
        }
    }
    
    for (const tFileName& fileName : fileNames)
    {
        answer.push_back(fileName.fileName);
    }
    

    //삽입정렬
    
    return answer;
}