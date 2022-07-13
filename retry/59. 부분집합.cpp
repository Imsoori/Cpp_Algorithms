
#include <iostream>
#include <vector>

using namespace std;

//59. 부분집합(dfs)

int n;
int visited[11];

void dfs(int level)
{

    if (level == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 1) printf("%d ", i);
        }
        puts("");
    }
    else {
        visited[level] = 1;
        dfs(level + 1);
        visited[level] = 0;
        dfs(level + 1);
    }
}

int main()
{
    scanf_s("%d", &n);

    dfs(1);

    return 0;
}

