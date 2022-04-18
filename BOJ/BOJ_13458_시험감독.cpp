
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, a, b, c;
long long int ans = 0;

vector <int> numStudent;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a; numStudent.push_back(a); }
	cin >> b >> c;


	for (int i = 0; i < n; i++)
	{
		// 총감독관
		ans += 1;
		numStudent[i] = numStudent[i] - b;

		if (numStudent[i] > 0) // 예외 케이스: 응시자가 1명인 경우 총감독관 만으로 가능
		{
			// 부감독관
			if (numStudent[i] % c == 0) ans += numStudent[i] / c;
			else ans += numStudent[i] / c + 1;
		}

	}

	cout << ans << endl;

	return 0;
}