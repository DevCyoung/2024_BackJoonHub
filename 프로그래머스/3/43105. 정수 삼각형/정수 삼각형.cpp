#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxNum = 0;

int searchMax(vector<int>& tree, vector<bool>& visited, const int pos, int d)
{    
    visited[pos] = true;
    
    int left = pos + d;
    int right = pos + d + 1;

    if (tree.size() <= left || tree.size() <= right)
    {
        return 0;
    }
    
    if (!visited[left])
    {
        searchMax(tree, visited, left, d + 1);
    }    
    if (!visited[right])
    {
        searchMax(tree, visited, right, d + 1);
    }    

    tree[pos] += tree[left] > tree[right] ? tree[left] : tree[right];    
    return 0;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> tree;
    vector<bool> visited;

    tree.reserve(1000000);
    visited.reserve(1000000);
    for (vector<int>& items : triangle)
    {
        for (int item : items)
        {
            tree.push_back(item);
            visited.push_back(false);
        }
    }

    
    searchMax(tree, visited, 0, 1);
    return tree[0];
}

