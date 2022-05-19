#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//1987. ¾ËÆÄºª
int r, c;
char m_map[25][25];
int checkAlphabet[30];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ans = 0;



void dfs(int y, int x, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx<0 || ny<0 || ny>r - 1 || nx>c - 1) continue;

		char nextAlpha = m_map[ny][nx];
		//cout << "ny, nx, value: " << ny << " " << nx << " " << nextAlpha << endl;
		if (checkAlphabet[nextAlpha - 'A'] == 0)
		{
			checkAlphabet[nextAlpha - 'A'] = 1;
			dfs(ny, nx, cnt + 1);
			checkAlphabet[nextAlpha - 'A'] = 0;

		}
		else {
			ans = max(ans, cnt);

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> m_map[i][j];
		}
	}

	char startAlpha = m_map[0][0];
	checkAlphabet[startAlpha - 'A'] = 1;
	dfs(0, 0, 1);

	cout << ans << endl;


	return 0;
}