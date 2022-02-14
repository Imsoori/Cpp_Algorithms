#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n,cnt=0;
    scanf("%d",&n);

    int flag;

    for(int i=2; i<n; i++)
    {   
        flag =1;
        for(int j= 2; j*j<i; j++)
        {
            if(i%j==0)
            {
                flag =0;
                break;
            }
        }
        if(flag)
        {
            cnt++;
        }
        
    }

    printf("%d",cnt);
    return 0;
}