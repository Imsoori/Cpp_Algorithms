#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//40. 교집합(투포인터 알고리즘)

int n, m;
int p1 = 0, p2 = 0, p3 = 0;



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> m;
	vector <int> b(m);
	vector <int> res(n + m);

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	while (p1 < n && p2 < m)
	{
		if (a[p1] == b[p2])
		{
			res[p3++] = a[p1++];
			p2++;
		}
		else if (a[p1] < b[p2]) p1++;
		else p2++;
	}


	for (int i = 0; i < p3; i++)
		cout << res[i] << " ";

	return 0;
}