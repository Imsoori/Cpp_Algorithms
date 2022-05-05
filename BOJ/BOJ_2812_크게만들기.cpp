//2812
#include <iostream>
#include <string>
#include <deque>
using namespace std;

string num, output = "";
int n, k;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	cin >> num;

	deque <char> dq;

	for (int i = 0; i < num.size(); i++)
	{
		while (!dq.empty() && dq.back() < num[i] && k)
		{
			k--;
			dq.pop_back();
		}
		dq.push_back(num[i]);
	}

	// �����ؾ��� k �� ���� �ִ� ��� �� ��� 
	for (int i = 0; i < dq.size() - k; i++)
	{
		output += dq[i];
	}


	cout << output << endl;

	return 0;
}