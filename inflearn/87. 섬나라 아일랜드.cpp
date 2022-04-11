#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//87. 섬나라 아일랜드
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
int map[25][25];
int visited[25][25];
int n;
vector <int> cnt;


int BFS(int cy, int cx)
{
	int cntisland = 1;
	queue <pair<int, int>> q;
	visited[cy][cx] = 1;
	q.push({ cx,cy });

	while (!q.empty())
	{

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx>n || ny>n)
				continue;

			if (visited[ny][nx] == 0 && map[ny][nx] == 1)
			{
				visited[ny][nx] = 1;
				cntisland++;
				q.push({ nx,ny });

			}
		}
	}

	return cntisland;
}


int main()
{

	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf_s("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)//y
	{
		for (int j = 1; j <= n; j++)//x
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				cnt.push_back(BFS(i, j));
			}
		}
	}

	cout << cnt.size() << endl;

	return 0;
}