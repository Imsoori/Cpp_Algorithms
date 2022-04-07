
// 69. BFS 
#include <iostream>
#include <vector>
using namespace std;

int n, s, e,x;
int Q[10], visited[10];
int front = -1, back = -1;
vector <int> maze[10];

int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &s, &e);
		maze[s].push_back(e);
		maze[e].push_back(s);
	}

	visited[1] = 1;
	Q[++back] = 1;

	while (front < back)
	{
		x = Q[++front];
		printf("%d ", x);
		for (int i = 0; i < maze[x].size(); i++)
		{
			if (visited[maze[x][i]] == 0)
			{
				visited[maze[x][i]] = 1;
				Q[++back] = maze[x][i];
			}
		}
	}

	return 0;
}