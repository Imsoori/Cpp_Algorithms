
#include <iostream>
#include <vector>
using namespace std;

//65. 미로 탐색 dfs

int m_maze[10][10];
int visited[10][10];
int result;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int depth = 0;

void dfs(int y, int x)
{
    int ny, nx;
    if (y == 6 && x == 6)
    {
        depth++;
    }
    else {
        for (int d = 0; d < 4; d++)
        {
            ny = y + dy[d];
            nx = x + dx[d];

            if (ny > 6 || nx > 6 || nx < 0 || ny < 0)
                continue;
            if (m_maze[ny][nx] == 0 && visited[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                dfs(ny, nx);
                visited[ny][nx] = 0;
            }


        }
    }
}

int main()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> m_maze[i][j];
            visited[i][j] = 0;
        }
    }

    visited[0][0] = 1;
    dfs(0, 0);

    cout << depth << endl;
    return 0;
}
