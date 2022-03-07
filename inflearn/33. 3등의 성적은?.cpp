define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <string>

using namespace std;

int main()

{
    int n,idx,tmp,grade, rank;

    int score[101] = {0,};

    scanf_s("%d", &n);



    for (int i = 0; i < n; i++)

    {

        scanf_s("%d", &score[i]);

    }



    for (int i = 0; i < n - 1; i++)

    {

        idx = i;

        for (int j = i + 1; j < n; j++)

        {

            if (score[j] > score[idx]) idx = j;

        }

        tmp = score[idx];

        score[idx] = score[i];

        score[i] = tmp;

    }

    grade = score[0];

    rank = 1;

    for (int i = 1; i < n; i++)

    {

        if (grade > score[i])

        {

            rank++;

            grade = score[i];

        }



        if (rank == 3)

        {

            printf("%d\n", score[i]);

            break;

        }

    }





    return 0;

}
