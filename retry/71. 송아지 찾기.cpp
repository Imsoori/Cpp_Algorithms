
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//71. 송아지 찾기 

int s, e;
int cnt;
int curPos, nxtPos;
int dir[3] = { -1,1,5 };
int visited[10001];
queue <int> pos;

int main()
{
    scanf_s("%d %d", &s, &e);

    visited[s] = 1;
    pos.push(s);

    while (!pos.empty())
    {
        curPos = pos.front();
        pos.pop();

        for (int d = 0; d < 3; d++)
        {
            nxtPos = curPos + dir[d];

            if (nxtPos < 0 || nxtPos>10001)
                continue;
            if (nxtPos == e)
            {
                printf("%d\n", visited[curPos]);
                return 0;
            }

            if (visited[nxtPos] == 0)
            {
                visited[nxtPos] = visited[curPos] + 1;
                pos.push(nxtPos);
            }
        }
    }


    return 0;
}

