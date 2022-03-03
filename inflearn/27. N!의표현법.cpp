#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, tmp,idx;
    int numberList[1001] = {0, };
    scanf_s("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        tmp = i;
        idx = 2;
        while (tmp != 1)
        {
            if (tmp % idx == 0)
            {
                numberList[idx]++;
                tmp = tmp / idx;
            }
            else {
                idx++;
            }
        }
    }

    printf("%d! = ", n);

    for (int i = 2; i <= n; i++)
    {
        if (numberList[i])
        {
            printf("%d ", numberList[i]);
        }

    }
    
    return 0;
}
