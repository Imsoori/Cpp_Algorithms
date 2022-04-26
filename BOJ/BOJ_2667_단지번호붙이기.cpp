#include<iostream>
#include<vector>
#include<queue>
#include <string>
#include<algorithm>

using namespace std;

int n;
char input;
int maze[30][30];
//int visited[26][26];
vector <int> ans;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs(int y, int x)
{
	queue <pair<int, int>> q;
	int blockCnt = 1;
	q.push({ y,x });
	maze[y][x] = 2;

	while (!q.empty())
	{
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) continue;

			if (maze[ny][nx] == 1)
			{
				blockCnt++;
				maze[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}

	ans.push_back(blockCnt);

}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			cin >> input;
			maze[i][j] = input - '0';
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}

	cout << ans.size() << endl;

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}