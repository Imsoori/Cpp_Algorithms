#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//40. 교집합(투포인터 알고리즘)

int n, m, tmp;
int pointerA = 0, pointerB = 0;
vector <int> a;
vector <int> b;
vector <int> res;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp; a.push_back(tmp);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp; b.push_back(tmp);
	}


	sort(a.begin(), a.end());
	sort(b.begin(), b.end());



	for (; pointerA < n;)
	{
		if (pointerA == n || pointerB == m) break;
		if (a[pointerA] == b[pointerB])
		{
			res.push_back(a[pointerA]);
			pointerA++;
			pointerB++;
		}
		else if (a[pointerA] < b[pointerB])
		{
			pointerA++;
		}
		else
		{
			pointerB++;
		}
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

	return 0;
}