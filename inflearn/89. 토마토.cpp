#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//89. 토마토
int n, m;
int** box;
queue <pair<int, int>> q;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void RipeCal()
{
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1)
				continue;
			if (box[ny][nx] == 0)
			{
				box[ny][nx] = box[cy][cx] + 1;
				q.push({ ny,nx });
			}

		}
	}


}
//void checkVisited()
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << box[i][j] << " ";
//		}
//		cout << endl;
//	}
//}


int cntDay()
{
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 0) {
				return -1;
			}
			else {
				if (box[i][j] > max) max = box[i][j];
			}
		}
	}
	return max - 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	int ripeCheck = 0;
	int emptyCheck = 0;

	box = new int* [n];
	for (int i = 0; i < n; i++)
	{
		box[i] = new int[m];
	}


	for (int i = 0; i < n; i++)// y
	{
		for (int j = 0; j < m; j++) //x
		{
			cin >> box[i][j];
			if (box[i][j] == 1) { ripeCheck++; q.push({ i,j }); }
			else if (box[i][j] == -1) { emptyCheck++; }

		}
	}

	// 저장될때부터 모든 토마토가 익은 상황
	if (m * n == ripeCheck + emptyCheck)
	{
		cout << 0 << endl;
		return 0;
	}


	RipeCal();

	cout << cntDay() << endl;

	//checkVisited();

	return 0;
}