
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 17090. 미로탈출하기
// DFS + DP;memoization

// state 
// -1 : 아직 방문하지 않은 칸
// 0 : 방문했으나 탈출 불가능
// 1 : 방문했고 탈출 가능 

int n, m;
char maze[505][505];
int state[505][505];
int cnt = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int Convert2Dir(char c)
{
	if (c == 'U') return 2;
	else if (c == 'R') return 1;
	else if (c == 'D') return 0;
	else  return 3;
}

int DFS(int y, int x)
{
	// memoization
	if (x<1 || y< 1 || x>m || y>n) return 1;
	if (state[y][x] != -1) return state[y][x];


	state[y][x] = 0;
	int moveState = Convert2Dir(maze[y][x]);

	int nx = x + dx[moveState];
	int ny = y + dy[moveState];

	return state[y][x] = DFS(ny, nx);


}



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin.tie(NULL);
	cin >> n >> m;

	//Input();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> maze[i][j];
			state[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{

			cnt += DFS(i, j);

		}
	}

	cout << cnt;

	return 0;
}