#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <deque>
using namespace std;

//2. 네트워크 선 자르기(top_down)

int dp[50];
int n;

int dfs(int a)
{
	if (dp[a] > 0) return dp[a];
	if (a == 1 || a == 2) return a;
	else return dp[a] = dfs(a - 1) + dfs(a - 2);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	cout << dfs(n);

	return 0;
}