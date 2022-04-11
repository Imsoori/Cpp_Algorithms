#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//88. 미로의 최단거리 통로 
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int map[8][8];
int visited[8][8];
queue <pair<int, int>> q;

int main()
{
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			scanf_s("%d", &map[i][j]);
		}
	}

	q.push({ 1,1 });
	//visited[1][1] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx>7 || ny>7)
				continue;
			if (visited[ny][nx] == 0 && map[ny][nx] == 0)
			{
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ nx,ny });
			}
		}
	}

	if (visited[7][7]) printf("%d\n", visited[7][7]);
	else printf("-1\n");

	return 0;
}