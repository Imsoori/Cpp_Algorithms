#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


////15686. 치킨배달
#define maxDis 2147000000
int n, m, eachAns, ans, result = maxDis;
int tmpInput;
int visited[14];
vector < pair<int, int>> Home;
vector < pair<int, int>> Pizza;


int caldis()
{
	int dis = maxDis;
	ans = 0;
	for (int i = 0; i < Home.size(); i++)
	{
		eachAns = maxDis;
		for (int j = 0; j < 14; j++)
		{
			if (visited[j])
			{
				dis = abs(Home[i].first - Pizza[j].first) + abs(Home[i].second - Pizza[j].second);
				eachAns = min(eachAns, dis);
			}
		}
		ans += eachAns;
	}

	return ans;

}

void FindCase(int refPoint, int cntCase)
{
	if (cntCase == m)
	{
		/*cout << "==================" << endl;
		for (int i = 0; i < 13; i++)
		{
			if (visited[i]) cout << i << " ";
		}
		cout << endl;*/
		result = min(caldis(), result);

		return;
	}
	else {
		for (int i = refPoint; i < Pizza.size(); i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				FindCase(i + 1, cntCase + 1);
				visited[i] = 0;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;;

	for (int i = 1; i <= n; i++) //y
	{
		for (int j = 1; j <= n; j++) // x
		{
			cin >> tmpInput;
			if (tmpInput == 1)
			{
				Home.push_back({ i,j });
			}
			else if (tmpInput == 2)
			{
				Pizza.push_back({ i,j });
			}
		}
	}

	FindCase(0, 0);

	cout << result << endl;



	return 0;
}