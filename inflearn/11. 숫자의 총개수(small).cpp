#include <iostream>
#include <string>
using namespace std;


int main()
{
    int n, tmp, cnt=0;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        tmp = i;
        while(tmp>0)
        {
            tmp = tmp/10;
            cnt++;
        }

    }
    printf("%d",cnt);
    return 0;
}