#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 1759. 암호만들기
int l, c;
vector <char> v;
int visited[20];
void dfs(int depth, int cnt)
{
	if (cnt == l)
	{
		int Mcnt = 0, Jcnt = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (visited[i])
			{
				if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
				{
					Mcnt++;
				}
				else {
					Jcnt++;
				}
			}
		}

		if (Mcnt >= 1 && Jcnt >= 2)
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (visited[i])
				{
					cout << v[i];
				}
			}
			cout << endl;
		}

	}
	else {
		for (int i = depth; i < v.size(); i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				dfs(i, cnt + 1);
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> l >> c;
	v.resize(c);

	for (int i = 0; i < c; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	dfs(0, 0);

	return 0;
}