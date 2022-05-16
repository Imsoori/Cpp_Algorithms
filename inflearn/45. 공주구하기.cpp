#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


//45. 공주구하기 
int n, k;
queue <int> prince;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		prince.push(i);
	}

	while (prince.size() != 1)
	{

		for (int i = 1; i < k; i++)
		{
			int currentNum = prince.front();
			prince.pop();
			prince.push(currentNum);
		}
		prince.pop();

	}


	cout << prince.front() << endl;

	return 0;
}