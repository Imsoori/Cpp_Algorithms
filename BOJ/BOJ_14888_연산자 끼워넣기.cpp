#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//14888. 연산자 끼워넣기
int numMax = -2147000000, numMin = 2147000000;
int n;
int calculator[4]; // + - * /
int arr[102];

void dfs(int node, int sum)
{
	if (node == n)
	{
		numMax = max(sum, numMax);
		numMin = min(sum, numMin);
	}
	else {
		if (calculator[0] > 0)
		{
			calculator[0]--;
			dfs(node + 1, sum + arr[node + 1]);
			calculator[0]++;
		}
		if (calculator[1] > 0)
		{
			calculator[1]--;
			dfs(node + 1, sum - arr[node + 1]);
			calculator[1]++;
		}
		if (calculator[2] > 0)
		{
			calculator[2]--;
			dfs(node + 1, sum * arr[node + 1]);
			calculator[2]++;
		}
		if (calculator[3] > 0)
		{
			calculator[3]--;
			dfs(node + 1, sum / arr[node + 1]);
			calculator[3]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
		cin >> calculator[i];

	dfs(1, arr[1]);


	cout << numMax << "\n" << numMin;

	return 0;
}