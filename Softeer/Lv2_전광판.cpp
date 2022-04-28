#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int n, ans;
queue <pair<int, int>> inputQ;
vector <vector<int>> dpA(5, vector<int>(7, 0));
vector <vector<int>> dpB(5, vector<int>(7, 0));

vector<int> Num2Switch(int num);

vector <vector<int>> definePos(int numA)
{
	vector <vector<int>> display(5, vector<int>(7, 0));
	int numa = numA;
	queue <int> QA;
	vector <int> VA;

	while (numa > 0)
	{
		QA.push(numa % 10);
		numa = numa / 10;
	}

	int idx = 4;
	while (!QA.empty())
	{
		int currentNumA = QA.front();
		QA.pop();
		VA = Num2Switch(currentNumA);

		for (int i = 0; i < VA.size(); i++)
		{
			display[idx][i] = VA[i];
		}
		idx--;
	}
	return display;
}

int compareAB()
{
	int cnt = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (dpA[i][j] != dpB[i][j])
			{
				cnt++;
			}
		}
	}
	return cnt;
}


vector<int> Num2Switch(int num)
{
	vector<int> disp;

	if (num == 0)
	{
		disp = { 1,1,1,0,1,1,1 };
	}
	else if (num == 1)
	{
		disp = { 0,0,1,0,0,0,1 };
	}
	else if (num == 2)
	{
		disp = { 1,0,1,1,1,1,0 };
	}
	else if (num == 3)
	{
		disp = { 1,0,1,1,0,1,1 };
	}
	else if (num == 4)
	{
		disp = { 0,1,1,1,0,0,1 };
	}
	else if (num == 5)
	{
		disp = { 1,1,0,1,0,1,1 };
	}
	else if (num == 6)
	{
		disp = { 1,1,0,1,1,1,1 };
	}
	else if (num == 7)
	{
		disp = { 1,1,1,0,0,0,1 };
	}
	else if (num == 8)
	{
		disp = { 1,1,1,1,1,1,1 };
	}
	else if (num == 9)
	{
		disp = { 1,1,1,1,0,1,1 };
	}

	return disp;
}

int main(int argc, char** argv)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		inputQ.push({ a,b });
	}

	while (!inputQ.empty())
	{
		int a = inputQ.front().first;
		int b = inputQ.front().second;
		inputQ.pop();

		dpA = definePos(a);
		dpB = definePos(b);
		ans = compareAB();
		cout << ans << endl;
	}



	return 0;
}