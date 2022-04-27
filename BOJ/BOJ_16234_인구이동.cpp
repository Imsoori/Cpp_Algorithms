#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include <memory.h>
using namespace std;

// 16234. 인구 이동
int n, l, r, cntPeople, cntBox;
int maze[55][55];
int visited[55][55];
int day = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector <pair<int, int>> v;


void  dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) continue;

		int diff = abs(maze[ny][nx] - maze[y][x]);

		if (visited[ny][nx] == 0 && diff >= l && diff <= r)
		{
			visited[ny][nx] = 1;
			cntBox++;
			cntPeople += maze[ny][nx];
			v.push_back({ ny,nx });
			dfs(ny, nx);
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
		}
	}


	while (1)
	{
		memset(visited, 0, sizeof(visited));
		bool found = false;

		// 인구 이동의 핵심!!
		// 인구이동 후 visited가 초기화 되어야함.
		// 인구이동 후 (0,0) 부터 다시 탐색해야함.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] == 0)
				{
					visited[i][j] = 1;
					cntPeople = maze[i][j];
					cntBox = 1;

					v.clear();
					v.push_back({ i,j });
					dfs(i, j);

					if (cntBox > 1)
					{
						found = true;
						for (int i = 0; i < v.size(); i++)
						{
							maze[v[i].first][v[i].second] = cntPeople / cntBox;
						}
					}

				}
			}
		}
		if (found)
		{
			day++;
		}
		else {
			break;
		}

	}


	cout << day << endl;

	return 0;
}