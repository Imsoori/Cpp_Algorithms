#include <iostream>
using namespace std;

int visited[21];
int adj[21][21];
int n, m;
int s, e;
int cnt = 0;

void DFS(int node)
{
    if (node == n)
    {
        cnt++;
    }
    else {
        for (int i = 1; i <= n; i++)
        {
            if (adj[node][i] && visited[i] == 0)
            {
                visited[i] = 1;
                DFS(i);
                visited[i] = 0;
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
        adj[s][e] = 1;
    }

    visited[1] = 1;
    DFS(1);

    printf("%d\n", cnt);

    return 0;
}
