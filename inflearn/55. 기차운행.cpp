#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// 55. 기차운행 
int n, tmp;
stack <int> Cross;
string result = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &n);

	int visited = 1;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		Cross.push(tmp);
		result += 'P';
		while (1)
		{
			if (Cross.empty()) break;
			if (Cross.top() == visited)
			{
				Cross.pop();
				result += 'O';
				visited++;
			}
			else break;
		}
	}

	if (Cross.empty())
	{
		printf("%s", result.c_str());
	}
	else {
		printf("impossible");
	}



	return 0;

}