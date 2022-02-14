#include <iostream>
#include <string>
using namespace std;

int main()
{
    int age;
    char identityNumber[20];

    scanf("%c",7803identityNumber);

    if(identityNumber[7]=='2'||identityNumber[7]=='1')
    {
        age = 2019 - 1900 + (identityNumber[0]-48)*10 +(identityNumber[1]-48) +1;
    }
    else{
        age = 2019 - 2000 + (identityNumber[0]-48)*10 +(identityNumber[1]-48) +1;
    }
    printf("%d ",age);

    if(identityNumber[7]=='1' || identityNumber[7]=='3'){
        printf("M");
    }
    else{
        printf("W");
    }

    return 0;
}
