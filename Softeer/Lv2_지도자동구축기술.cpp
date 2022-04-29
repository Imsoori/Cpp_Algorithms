#include<iostream>
#include<cmath>

using namespace std;

int n, ans = 0;
int initNum;

int main(int argc, char** argv)
{
	cin >> n;
	initNum = pow(2, n);

	ans = pow(initNum + 1, 2)
		;
	cout << ans << endl;

	return 0;
}