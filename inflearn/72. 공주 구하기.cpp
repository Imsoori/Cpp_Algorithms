#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//72. 공주 구하기
queue <int> q;
int n, k, x, cnt=1;

int main()
{
    scanf("%d %d",&n, &k);

    for(int i=1; i<=n;i++)
    {
        q.push(i);
    }

    while(!q.empty())
    {
        x = q.front();
        q.pop();

        if(cnt!=k)
        {
            cnt++;
            q.push(x);
        }
        else{
            cnt=1;
        }
    }

    printf("%d\n",x);

    return 0;
}