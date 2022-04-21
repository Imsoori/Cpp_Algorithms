#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//35. Special sort; 구글인터뷰
queue <int> pq, ansq;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int input;


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		if (input < 0)
		{
			ansq.push(input);
		}
		else {
			pq.push(input);
		}
	}

	while (!pq.empty())
	{
		ansq.push(pq.front());
		pq.pop();
	}

	while (!ansq.empty())
	{
		cout << ansq.front() << " ";
		ansq.pop();
	}



	return 0;
}