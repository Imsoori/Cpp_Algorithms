#include <iostream>
#include <queue>
using namespace std;

//71. 송아지 찾기
int s,e,curPos,nxtPos;
int cnt,minCnt=0;
int visited[10001];
int dir[3]={1,-1,5};
queue <int> pos;

int main()
{
    scanf("%d %d", &s, &e);
    
    visited[s]=1;
    pos.push(s);

    while(!pos.empty())
    {
        curPos = pos.front();
        pos.pop();

        for(int i=0; i<3; i++)
        {
            nxtPos = curPos + dir[i];
            if(nxtPos<0 || nxtPos>10001)
                continue;
            if(nxtPos==e)
            {
                printf("%d\n",visited[curPos]);
                return 0;
            }
            if(visited[nxtPos]==0)
            {
                visited[nxtPos] = visited[curPos] +1;
                pos.push(nxtPos);
            }
        }
        
    }

    return 0;
}