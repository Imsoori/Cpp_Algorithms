define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <string>

using namespace std;



int main()

{



    char compound[10];

    scanf("%s", compound);



    int c=0, h=0, i, pos;



    if (compound[1] == 'H')

    {

        c = 1;

        pos = 1;

    }

    else {

        for (i = 1; compound[i] != 'H'; i++)

        {

            c = c * 10 + (compound[i] - 48);

        }

        pos = i;

    }



    if (compound[pos + 1] == '\0') h = 1;

    else {

        for (i = pos + 1; compound[i] != '\0'; i++)

        {

            h = h * 10 + (compound[i] - 48);

        }

    }



    printf("%d", c * 12 + h);



    return 0;

}
