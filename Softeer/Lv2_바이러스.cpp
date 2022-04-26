#include<iostream>


using namespace std;

#define OUT 1000000007

long long int k, p, n;


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> p >> n;

	for (int i = 0; i < n; i++)
	{
		k = (k * p) % OUT;
	}
	cout << k << endl;

	return 0;
}