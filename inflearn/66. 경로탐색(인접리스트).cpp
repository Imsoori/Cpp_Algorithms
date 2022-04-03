#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[21];
int visited[21] = {0,};
int n, m,res;
int s, e;


void DFS(int node)
{
	if (node == n)
	{
		res++;
	}
	else {
		for (int i = 0; i < graph[node].size(); i++)
		{
			if ( !visited[graph[node][i]])
			{
				visited[graph[node][i]] = 1;
				DFS(graph[node][i]);
				visited[graph[node][i]] = 0;
			}
		}
	}
}



int main()
{
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &s, &e);
		graph[s].push_back(e);
	}

	visited[1] = 1;
	DFS(1);

	printf("%d\n", res);
	return 0;
}