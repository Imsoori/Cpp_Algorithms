#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int m_maze[51][51];
int tmp_maze[51][51];
int n,m,cntTime;
int selectVirusPos[11];
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int visited[51][51];
int minAns = 2147000000;
vector <pair<int,int> > virusPosList;

// 17141. 연구소2
// 아래 예외 처리 필요
입력 : 5 6
0 1 0 1 0
2 0 2 0 2
0 1 0 1 0
2 0 2 0 2
0 1 0 1 0
예상 출력 : 1
입력 :5 2
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 2 2 1
예상 출력 : 0

int spreadVirus()
{
    queue <pair<int, int> > virusPos;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp_maze[i][j] = m_maze[i][j];
            visited[i][j]=0;
            
            if(tmp_maze[i][j]==2)
            {
                tmp_maze[i][j]=0;
            }

        }
    }

    for(int i=0; i<virusPosList.size(); i++)
    {
        if(selectVirusPos[i])
        {
            virusPos.push(virusPosList[i]);
        }
    }
   

    while(!virusPos.empty())
    {
        int cy = virusPos.front().first;
        int cx = virusPos.front().second;
       // visited[cy][cx]=1;
        virusPos.pop();
        
        for(int d=0; d<4; d++)
        {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1) continue;

			if (tmp_maze[ny][nx] == 0 && visited[ny][nx]==0)
			{
                visited[ny][nx]=1;
				tmp_maze[ny][nx] = tmp_maze[cy][cx]+1;
				virusPos.push(make_pair(ny,nx ));
			}
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(tmp_maze[i][j]==0)
            {
                return -1;
            }
            else if(tmp_maze[i][j]>ans)
            {
                ans = tmp_maze[i][j];
            }
        }
        
    }
   // cout<<ans<<endl;
    return ans;
    

}


void findVirusStartPos(int L, int r)
{
    if(r==m)
    {
        cntTime = spreadVirus();
        if(cntTime != -1)
        {
            minAns = min(cntTime, minAns);
            return;
        }
        
    }
    else{
        for(int i=L; i<virusPosList.size(); i++)
        {
            if(selectVirusPos[i]==0)
            {
                selectVirusPos[i] =1;
                findVirusStartPos(i+1, r+1);
                selectVirusPos[i] =0;
            }
        }
    }
}


int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>> m_maze[i][j];
            
            if(m_maze[i][j]==2)
            {
                virusPosList.push_back(make_pair(i,j));
            }
        }
    }

    findVirusStartPos(0,0);

    if(minAns == 2147000000)
    {
        minAns = -1;
    }
    cout<<minAns<<endl;

    return 0;
}