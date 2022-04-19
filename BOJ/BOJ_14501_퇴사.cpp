#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//14501 Επ»η
vector <pair<int, int>> v; // time, cost
int n, x, y;
int ans = 0, ansMax = 0;
int tmp = 0;

int dp(int time)
{
	/*if (time == n) return 0;
	if (time > n) return -2147000000;*/
	int t = v[time].first;
	int p = v[time].second;

	if (time == n) return p;
	if (time > n)  return -2147000000;

	tmp = max(p + dp(time + t), dp(time + 1));

	return  tmp;

}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}

	ans = dp(0);
	cout << ans << endl;

	return 0;
}