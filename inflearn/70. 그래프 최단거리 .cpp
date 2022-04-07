
// 70.  
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, s, e, x;
int visited[21], dis[21];
vector <int> maze[21];
queue <int> q;

int main()
{
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &s, &e);
		maze[s].push_back(e);
	}

	visited[1] = 1;
	q.push(1);

	while (!q.empty())
	{
		x = q.front();
		q.pop();

		for (int i =0; i < maze[x].size(); i++)
		{
			if (visited[maze[x][i]] == 0)
			{
				visited[maze[x][i]] = 1;
				q.push(maze[x][i]);
				dis[maze[x][i]] = dis[x] + 1;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		printf("%d : %d\n", i, dis[x]);
	}

	return 0;
}