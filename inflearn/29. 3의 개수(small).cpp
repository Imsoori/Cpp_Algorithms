#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, tmp, cntThree=0;
    scanf_s("%d", &n);


    for (int i = 1; i <= n; i++)
    {
        tmp = i;

        while (tmp > 0)
        {
            if (tmp % 10 == 3)
            {
                cntThree++;
            }
            tmp = tmp / 10;
        }
    }
    printf("%d\n", cntThree);

    return 0;
}
