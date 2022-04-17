#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 17090. 미로탈출하기
int n, m;
char maze[505][505];
int visited[505][505];
int cnt = 0;


void DFS(int y, int x)
{
	if (y > n || y<1 || x>m || x < 1)
	{
		cnt++;
		return;
	}
	else {
		if (visited[y][x] == 0)
		{
			if (maze[y][x] == 'U')
			{
				visited[y][x] = 1;
				DFS(y - 1, x);
				visited[y][x] = 0;
			}
			if (maze[y][x] == 'D')
			{
				visited[y][x] = 1;
				DFS(y + 1, x);
				visited[y][x] = 0;
			}
			if (maze[y][x] == 'R')
			{
				visited[y][x] = 1;
				DFS(y, x + 1);
				visited[y][x] = 0;
			}
			if (maze[y][x] == 'L')
			{
				visited[y][x] = 1;
				DFS(y, x - 1);
				visited[y][x] = 0;
			}

		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> maze[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			DFS(i, j);
		}
	}


	cout << cnt;

	return 0;
}