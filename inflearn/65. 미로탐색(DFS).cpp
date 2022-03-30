#include <iostream>
using namespace std;

int visited[10][10];
int map[10][10];
int n, m;
int s, e;
int cnt = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void DFS(int x, int y)
{
    int nx, ny;
    if (x==7 && y==7)
    {
        cnt++;
    }
    else {
        for (int i = 0; i <4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 1 || nx>7 || ny < 1 || ny>7)
                continue;
            if (map[nx][ny] == 0 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                DFS(nx, ny);
                visited[nx][ny] = 0;
            }
        }
    }
}
int main()
{
    
    for (int i = 1; i <=7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            scanf_s("%d", &map[i][j]);
            visited[i][j] = 0;
        }
    }

    visited[1][1] = 1;
    DFS(1,1);

    printf("%d\n", cnt);

    return 0;
}
