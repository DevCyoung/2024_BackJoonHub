#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int balance_check(char* str, int index, char start, int depth);

int main()
{
	while (1)
	{
		char str[200];
		fgets(str, 200, stdin);
		int index = 0;
		if (str[index] == '.')
			return 0;

		while (str[index] != '\0')
		{

			if (str[index] == ')' || str[index] == ']')
			{
				index = 0;
				break;
			}
			if (str[index] == '(' || str[index] == '[')
			{

				index = balance_check(str, index + 1, str[index], 0);
				if (index == 0)
					break;
			}
			index++;
		}

		if (index)
			printf("yes\n");
		else
			printf("no\n");

	}

}
int balance_check(char* str, int index, char start, int depth)
{
	char target = start == '(' ? ')' : ']';
	// 포인트가 오른쪽으로 계속해서 이동한다.
	while (str[index] != '\0')
	{

		if (start == '(' && target == ')' && str[index] == ']')
			return 0;
		else if (start == '[' && target == ']' && str[index] == ')')
			return 0;

		if (str[index] == '(' || str[index] == '[')
		{
			int next = balance_check(str, index + 1, str[index] , ++depth);
			if (next)
				index = next;
			else
				return 0;
		}
		else if (str[index] == target)		// 성공했을때.
			return index;
        
		++index;
		//끝까지 발견하지못한다면.
		if (str[index] == '\0')
			return 0;
	}
}