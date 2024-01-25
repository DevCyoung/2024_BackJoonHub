#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;
	int hambuger[4] = { 1, 2, 3, 1 };


	vector<int>::iterator it = ingredient.begin();
	vector<int> s;
	//prevburn

	while (it != ingredient.end())
	{		
		if (it + 3 < ingredient.end())
		{			
			if (*it == 1 && *(it + 1) == 2 && *(it + 2) == 3 && *(it + 3) == 1)
			{
				it = ingredient.erase(it, it + 4);			
				++answer;
				if (!s.empty())
				{
					it = ingredient.begin() + s.back();
					s.pop_back();
				}
				continue;
			}
			else if (*it == 1)
			{
				s.push_back(it - ingredient.begin());
			}
		}

		++it;
	}
	return answer;
}
