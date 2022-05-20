#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

const int MAX = 1001;

int N, M;
int start;

int MAP[MAX][MAX];
int visited[MAX];

queue <int> q;



void DFS(int idx)
{
	cout << idx << " ";

	for (int i = 1; i <= N; i++)
	{
		if (MAP[idx][i] && !visited[i])
		{
			visited[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int idx)
{
	q.push(idx);
	visited[idx] = 1;

	while (!q.empty())
	{
		idx = q.front();
		q.pop();

		cout << idx << " ";

		for (int i = 1; i <= N; i++)
		{
			if (MAP[idx][i] && !visited[i])
			{
				visited[i] = 1;
				q.push(i);
			}
		}


	}

}


int main()
{

	cin >> N >> M >> start;

	for (int i = 0; i < M; i++)
	{
		int from, to;

		cin >> from >> to;

		MAP[from][to] = 1;
		MAP[to][from] = 1;
	}

	visited[start] = 1;

	DFS(start);
	cout << endl;

	memset(visited, 0, sizeof(visited));

	BFS(start);
	cout << endl;

	return 0;

}