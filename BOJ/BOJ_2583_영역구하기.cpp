#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, k;
int m_map[101][101];
int a1, b1, a2, b2;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<int> ans;

int bfs(int y, int x)
{
	int cnt = 1;
	queue <pair<int, int>> q;
	q.push({ y,x });
	m_map[y][x] = 2;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (ny > m - 1 || nx > n - 1 || ny < 0 || nx < 0) continue;

			if (m_map[ny][nx] == 0)
			{
				m_map[ny][nx] = 2;// queue 방문함
				q.push({ ny,nx });
				cnt++;
			}
		}
	}
	return cnt;

}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> k; //m = 행

	for (int i = 1; i <= k; i++)
	{
		cin >> a1 >> b1 >> a2 >> b2;

		for (int y = b1; y < b2; y++) {
			for (int x = a1; x < a2; x++)
			{
				m_map[y][x] = 1;
			}
		}
	}

	/*for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << m_map[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (m_map[i][j] == 0)
			{
				ans.push_back(bfs(i, j));
			}

		}
	}

	cout << ans.size() << endl;

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}