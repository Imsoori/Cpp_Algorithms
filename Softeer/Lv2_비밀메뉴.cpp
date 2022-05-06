#include<iostream>
#include<vector>

// 2022-05-05 testcase 33-3 x
using namespace std;

int M, N, K;// , input;
vector <int> secretRecipe;
vector <int> customButton;
string output = "normal";

int main(int argc, char** argv)
{

	cin >> M >> N >> K;

	secretRecipe.resize(M);
	customButton.resize(N);

	for (int i = 0; i < M; i++)
	{
		cin >> secretRecipe[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> customButton[i];
	}

	int sIndex = 0;
	int cIndex = 0;
	int secretCnt = 0;

	while (cIndex < customButton.size())
	{
		if (secretRecipe[sIndex] == customButton[cIndex])
		{
			secretCnt++;
			sIndex++;
			cIndex++;
		}
		else {
			sIndex = 0;
			secretCnt = 0;
			if (secretRecipe[sIndex] != customButton[cIndex])
			{
				cIndex++;
			}
		}

		if (secretCnt == secretRecipe.size())
		{
			output = "secret";
			break;
		}
	}



	cout << output << endl;

	return 0;
}