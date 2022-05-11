#include<iostream>
#include<vector>
#include <queue>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input_str, output_str;

	cin >> input_str;

	for (int i = 0; i < input_str.size(); i++)
	{
		if (input_str[i] >= '0' && input_str[i] <= '9')
		{
			output_str += input_str[i];
		}
	}

	int num = stoi(output_str);
	int cnt = 0;

	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			cnt++;
		}
	}



	cout << num << endl;
	cout << cnt << endl;

	return 0;
}