#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <deque>
using namespace std;

//1. 네트워크 선 자르기(bottom_up)

int dp[50];
int n;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;
	return 0;
}