#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 82. 순열(dfs)


int n, r, cnt = 0;
int res[16], arrInput[16], visited[16];


void dfs(int L)
{
	if (L == r)
	{
		for (int i = 0; i < r; i++)
		{
			cout << res[i] << " ";
		}
		cnt++;
		puts(" ");
	}
	else {
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 0)
			{
				res[L] = arrInput[i];
				visited[i] = 1;
				dfs(L + 1);
				visited[i] = 0;
			}
		}
	}
}




int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r;
	for (int i = 0; i < n; i++)
	{
		cin >> arrInput[i];
	}


	dfs(0);

	cout << cnt << endl;
	return 0;
}
