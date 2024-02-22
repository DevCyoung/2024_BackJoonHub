#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> musicSplit(string str)
{
    vector<string> result;
    
    for (int i = 0; i < str.size(); ++i)
    {
        string temp = "";
        
        temp += str[i];
        if (i + 1 < str.size() && str[i + 1] == '#')
        {
            temp += str[i + 1];
            ++i;
        }
        result.push_back(temp);        
    }
    
    return result;
}

vector<string> comSplit(string str)
{
    vector<string> result;
    
    for (int i = 0; i < str.size(); ++i)
    {
        string temp = "";
        for (; i < str.size(); ++i)
        {
            if (str[i] == ',')
            {
                break;
            }
            temp += str[i];
        }        
        result.push_back(temp);
    }
    return result;
}

int getTime(string time)
{
    int hour = std::stoi(time.substr(0, 2));
    int miniute = std::stoi(time.substr(3, 2));
    
    return hour * 60 + miniute;
}

bool isThatMusic(const vector<string>& pitchs_m, const vector<string>& pitchs_musincInfo, const int time)
{
    int i = 0;
    while (i < time)
    {
        bool flag = true;
        int j = 0;
        int k = 0;
        int tempTime = time - i;

        while (j < pitchs_m.size())
        {            
            if (pitchs_musincInfo[(i + k) % pitchs_musincInfo.size()] != pitchs_m[j % pitchs_m.size()])
            {
                flag = false;
                break;                
            }            

            ++j;
            ++k;
            --tempTime;
        }        
        if (flag && tempTime >= 0)
        {
            return true;
        }
        
        ++i;
    }
    
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int tempTime = 0;
    
    for (string musicInfo: musicinfos)
    {        
        vector<string> infos                =  comSplit(musicInfo);        
        vector<string> pitchs_m             =  musicSplit(m);
        vector<string> pitchs_musicncInfo   =  musicSplit(infos[3]);
        int time                            =  getTime(infos[1]) - getTime(infos[0]);
        
        if (isThatMusic(pitchs_m, pitchs_musicncInfo, time))
        {
            if (tempTime < time)
            {
                tempTime = time;
                answer = infos[2];
            }
        }
    }    
    
    return answer;
}