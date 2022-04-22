#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//87. 섬나라 아일랜드
int n;
int maze[25][25];
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
queue <pair<int, int>> q;
int cnt = 0;


int bfs(int y, int x)
{
	maze[y][x] = 2;
	q.push({ y,x });

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx<0 || ny<0 || nx> n - 1 || ny>n - 1)
				continue;

			if (maze[ny][nx] == 1)
			{
				maze[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 1)
			{
				cnt += bfs(i, j);
			}

		}
	}

	cout << cnt << endl;

	return 0;
}