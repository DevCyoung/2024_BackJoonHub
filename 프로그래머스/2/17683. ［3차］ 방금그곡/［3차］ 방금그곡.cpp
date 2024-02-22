#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> pitchSplit(string str)
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
    for (int i = 0; i < time; ++i)
    {
        bool    flag     = true;        
        int     tempTime = time - i;

        for (int j = 0; j < pitchs_m.size(); ++j)
        {
            if (pitchs_m[j % pitchs_m.size()] != pitchs_musincInfo[(i + j) % pitchs_musincInfo.size()])
            {
                flag = false;
                break;                
            }                   
            --tempTime;
        }        
        if (flag && tempTime >= 0)
        {
            return true;
        }
    }
    
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int tempTime = 0;
    
    for (string musicInfo: musicinfos)
    {        
        vector<string> infos                =  comSplit(musicInfo);        
        vector<string> pitchs_m             =  pitchSplit(m);
        vector<string> pitchs_musicncInfo   =  pitchSplit(infos[3]);
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