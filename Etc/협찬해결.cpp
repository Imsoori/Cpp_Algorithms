#include <iostream>
using namespace std;

int N; 
int D[100000 + 10];
int sol = -30001; // first solve
int ans = -2147000000; // second solve 

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}
}

//first
void Solve()
{
	int i, sum = 0;
	for (i = 0; i < N - 2; i++) {
		sum = D[i] + D[i + 1] + D[i + 2];
		if (sum > sol) sol = sum;
	}
}

//seocnd time-out
void Answer()
{
	int sum;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sum = 0;
			for (int k = j; k < j + i; k++)
			{
				sum += D[k];
			}
			if (sum > ans) ans = sum;
		}

	}
}

// pass
void betAns()
{
	int sum = 0;
	ans = -10001;

	for (int i = 0; i < N; i++)
	{
		if (sum > 0) sum += D[i];
		else sum = D[i];
		if (sum > ans) ans = sum;
	}
}



int main() {
	InputData();
	betAns();
	cout << ans << endl;
	return 0;
}