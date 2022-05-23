#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <deque>
using namespace std;

//63.인접행렬

int n, m;
int s, e, value;
int m_map[25][25];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> value;
		m_map[s][e] = value;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << m_map[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}