#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//76. 이항 계수(메모이제이션)
int n, r;
int memo[21][21];

int Combination(int a, int b)
{
	if (memo[a][b]) return memo[a][b];
	if (a == b || b == 0) return 1;
	else {
		return memo[a][b] = Combination(a - 1, b) + Combination(a - 1, b - 1);
	}
}


int main()
{
	//nCr = n-1Cr-1 + n-1Cr;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r;

	cout << Combination(n, r);

	return 0;

}