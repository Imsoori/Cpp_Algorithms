#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, m;
int mat[21][21] = {0,};
int visited[21];
int row, col, cost;
int Min = 2147000000;
int res = 0;
int costSum = 0;

void DFS(int node,int sum)
{
    if (node == n)
    {
        if (sum < Min)
            Min = sum;
       
    }
    else {
        for (int i = 1; i <= n; i++)
        {
            if (mat[node][i] && !visited[i])
            {
                visited[i] = 1;
                DFS(i, sum+ mat[node][i]);
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
        scanf_s("%d %d %d", &row, &col, &cost);
        mat[row][col] = cost;
    }

    visited[1] = 1;
    DFS(1,0);

    printf("%d\n", Min);

    return 0;
}