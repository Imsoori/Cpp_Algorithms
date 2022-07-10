#include <iostream>
#include <vector>

using namespace std;

// 36. »ðÀÔÁ¤·Ä 22.07.10

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, tmp;
	int arr[101];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	int i, j;
	for (i = 1; i < n; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (tmp < arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}

		}
		arr[j + 1] = tmp;
	}


	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

}