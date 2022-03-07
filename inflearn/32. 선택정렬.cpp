define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <string>

using namespace std;



int main()

{

    int n, tmp,idx;

    int arr[101];

    scanf("%d", &n);

    

    for (int i = 0; i < n; i++)

    {

        scanf("%d", &arr[i]);

    }

    // selection sort()

    for (int i = 0; i < n-1; i++)

    {

        idx = i;

        for (int j = i + 1; j < n; j++)

        {

            if (arr[j] < arr[idx]) idx = j;

        }

        tmp = arr[idx];

        arr[idx] = arr[i];

        arr[i] = tmp;

    }



    for (int i = 0; i < n; i++)

    {

        printf("%d ", arr[i]);

    }



    return 0;

}
