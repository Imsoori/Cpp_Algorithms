#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//35. Special sort; 구글인터뷰


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a[101], n, tmp;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > 0 && a[j + 1] < 0)
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}