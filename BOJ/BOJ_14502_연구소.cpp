
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define emptySpace 100
// 14502. 연구소
int n, m, tmp;
int board[10][10];
int tmp_board[10][10];
vector <pair<int, int>> emptyPos;

int emptyCnt[emptySpace];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int maxAns = -2147000000;

int spreadVirus()
{
	queue <pair<int, int>> virusPos;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp_board[i][j] = board[i][j];

			if (board[i][j] == 2)
			{
				virusPos.push({ i,j });
			}
		}
	}

	for (int i = 0; i < emptySpace; i++)
	{
		if (emptyCnt[i])
		{
			int y = emptyPos[i].first;
			int x = emptyPos[i].second;

			tmp_board[y][x] = 3;
		}
	}


	while (!virusPos.empty())
	{
		int cy = virusPos.front().first;
		int cx = virusPos.front().second;
		virusPos.pop();

		for (int d = 0; d < 4; d++)
		{
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1) continue;
			if (tmp_board[ny][nx] == 0)
			{
				tmp_board[ny][nx] = 2;
				virusPos.push({ ny,nx });
			}
		}

	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (tmp_board[i][j] == 0)
			{
				ans++;
			}
		}
	}

	return ans;

}


void findPosition(int L, int r)
{
	if (r == 3)
	{
		tmp = spreadVirus();
		maxAns = max(maxAns, tmp);
		return;
	}
	else {
		for (int i = L; i < emptyPos.size(); i++)
		{
			if (emptyCnt[i] == 0)
			{
				emptyCnt[i] = 1;
				findPosition(i + 1, r + 1);
				emptyCnt[i] = 0;

			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 0)
			{
				emptyPos.push_back({ i,j }); //y,x
			}


		}
	}

	findPosition(0, 0);

	cout << maxAns << endl;

	return 0;
}