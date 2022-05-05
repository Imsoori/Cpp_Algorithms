//2812. 시간초과..dfs 접근
#include <iostream>
#include <string>
using namespace std;

string num, output = "", str;
int n, k;
int visited[500001];

void dfs(int l, int c)
{

	if (c == n - k)
	{
		str.clear();
		for (int i = 0; i < num.size(); i++)
		{
			if (visited[i] == 1)
			{
				str += num[i];
			}

		}
		output = max(output, str);

		//cout << str << endl;
		return;
	}
	else {
		for (int i = l; i < num.size(); i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				dfs(i + 1, c + 1);
				visited[i] = 0;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	cin >> num;

	dfs(0, 0);

	cout << output << endl;
	return 0;
}