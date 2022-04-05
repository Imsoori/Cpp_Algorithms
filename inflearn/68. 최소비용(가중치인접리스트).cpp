
// 68. 
#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int>> graph[21];
int visited[21];
int n, m,s,e,cost;
int minCost=2147000000;

void DFS(int node, int sum)
{
	if (node == n)
	{
		if (minCost > sum)
		{
			minCost = sum;
		}
	}
	else {
		for (int i = 0; i < graph[node].size(); i++)
		{
			int nextNode = graph[node][i].first;
			int pathCost = graph[node][i].second;
			if (visited[nextNode] == 0)
			{
				visited[nextNode] = 1;
				DFS(nextNode, sum + pathCost);
				visited[nextNode] = 0;

			}
		}
	}
}


int main()
{
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &s, &e, &cost);
		graph[s].push_back({ e,cost });

	}

	visited[1] = 1;
	DFS(1, 0);

	printf("%d\n", minCost);

	return 0;
}