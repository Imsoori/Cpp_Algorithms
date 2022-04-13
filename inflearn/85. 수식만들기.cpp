#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/// 85.수식만들기
int n;
int calculator[4];
int arr[15];
int Min = 2147000000, Max = -2147000000;

void DFS(int numPos, int sum)
{
	if (numPos == n)
	{
		Min = min(Min, sum);
		Max = max(Max, sum);
	}
	else {
		if (calculator[0] > 0)
		{
			calculator[0]--;
			DFS(numPos + 1, sum + arr[numPos + 1]);
			calculator[0]++;
		}
		if (calculator[1] > 0)
		{
			calculator[1]--;
			DFS(numPos + 1, sum - arr[numPos + 1]);
			calculator[1]++;
		}
		if (calculator[2] > 0)
		{
			calculator[2]--;
			DFS(numPos + 1, sum * arr[numPos + 1]);
			calculator[2]++;
		}
		if (calculator[3] > 0)
		{
			calculator[3]--;
			DFS(numPos + 1, sum / arr[numPos + 1]);
			calculator[3]++;
		}
	}
}

int main()
{
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf_s("%d", &arr[i]);

	for (int i = 0; i < 4; i++)
		scanf_s("%d", &calculator[i]);

	DFS(1, arr[1]);

	printf("%d\n%d\n", Max, Min);

	return 0;
}
