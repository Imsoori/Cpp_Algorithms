#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;

// 2267. 단지번호 붙이기
int N;
char in;
int m_map[30][30];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

vector <int> ans; 

void bfs(int y, int x)
{
    queue <pair<int,int> > mq;
    int cx,cy,nx,ny;
    int idx =1;
    m_map[y][x]=2;
    mq.push(make_pair(y,x));

    while(!mq.empty())
    {
        cy = mq.front().first;
        cx = mq.front().second;
        mq.pop();

        for(int d=0; d<4 ;d++)
        {
            ny = cy + dy[d];
            nx = cx + dx[d];

            if(ny<0 || ny>=N || nx<0 ||nx>=N)
                continue;

            if(m_map[ny][nx]==1)
            {
                mq.push(make_pair(ny,nx));
                m_map[ny][nx]=2;
                idx++;
            }
           

        }
    }

    ans.push_back(idx);
}



int main()
{
    cin>>N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>in;
            m_map[i][j] = in-'0';            
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(m_map[i][j]==1)
                bfs(i,j);
        }
    }

    cout<<ans.size()<<endl;

    sort(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;

    return 0;
}