//#include<vector>
#include<cstring>
#include <queue>
using namespace std;

struct tNode
{
	int x;
	int y;
};

int solution(vector<vector<int> > maps)
{	
	int w = maps[0].size();
	int h = maps.size();

	int dx[4] = { 1, 0, -1,  0};
	int dy[4] = { 0, -1, 0,  1};
    
	int distances[100][100];
	bool bVisiteds[100][100];	

	queue<tNode> nodes;
	nodes.push({ 0, 0 });	

	memset(distances, 0, sizeof(distances));
	memset(bVisiteds, false, sizeof(bVisiteds));

	distances[0][0] = 1;
    bVisiteds[0][0] = true;
    
	while (!nodes.empty())
	{
		tNode node = nodes.front();
		nodes.pop();

		//bVisiteds[node.y][node.x] = true;

		for (int i = 0; i < 4; ++i)
		{
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];

			if (nx < 0 || nx >= w || ny < 0 || ny >= h)
			{
				continue;
			}
			else if (maps[ny][nx] == 0)
			{
				continue;
			}
			else if (bVisiteds[ny][nx])
			{
				continue;
			}

			distances[ny][nx] = distances[node.y][node.x] + 1;
            bVisiteds[ny][nx] = true;
			if (ny == h - 1 && nx == w - 1)
			{
				nodes = queue<tNode>();                
				break;
			}			
            
            tNode nNode{ nx, ny };
			nodes.push(nNode);
		}
	}

	if (distances[h - 1][w - 1] == 0)
	{
		distances[h - 1][w - 1] = -1;
	}

	return distances[h - 1][w - 1];
}
