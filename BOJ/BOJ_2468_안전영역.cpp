#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

//2468. 안전 영역

int n;
int m_map[101][101];
int check[101][101];
int height[101];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ans = 1;
int maxHeight = 0;
vector <int> v;

int bfs(int y, int x)
{
	queue <pair<int, int>> q;
	q.push({ y,x });
	check[y][x] = 2;
	int cnt = 1;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (ny<0 || nx<0 || ny>n - 1 || nx>n - 1) continue;

			if (check[ny][nx] == 1)
			{
				check[ny][nx] = 2;
				q.push({ ny,nx });
				cnt++;
			}
		}
	}

	return cnt;
}


int rainMap(int h)
{
	memset(check, 0, sizeof(check));
	// map
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (m_map[i][j] > h)
			{
				check[i][j] = 1;
			}
			else {
				check[i][j] = 0;
			}
		}
	}

	v.clear();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == 1)
			{
				//ut << "h y x " << h << " " << i << " " << j << endl;
				//cout << bfs(i, j) << endl;
				v.push_back(bfs(i, j));
			}
		}
	}

	return v.size();
}




int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m_map[i][j];

			///maxHeight = max(maxHeight, m_map[i][j]);
			if (height[m_map[i][j]] == 0)
			{
				height[m_map[i][j]] = 1;
			}
		}
	}


	for (int i = 1; i < 101; i++)
	{
		if (height[i] == 1)
		{
			ans = max(ans, rainMap(i));
			// ans =1 로 초기화 해야하는이유
			// 아무 지역도 물에 잠기지 않을 수 있다.
			// 입력
			// 2
			// 1 1
			// 1 1
			// 출력
			// 1
		}
	}
	cout << ans << endl;


	return 0;
}