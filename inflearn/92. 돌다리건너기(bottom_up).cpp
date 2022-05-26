#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <deque>
using namespace std;

// 3. 돌다리 건너기 (bottom-up)

int dp[50];
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n + 1; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n + 1] << endl;

	return 0;
}