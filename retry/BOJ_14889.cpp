#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;

// 14889. 스타트링크 
int n;
int ans = 2147000000;
int visited[30];
int m_map[30][30];

int scoreSum(vector <int> v)
{
    int res=0;

    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            res += m_map[v[i]][v[j]];
        }
    }

    return res;
}


void dfs(int node, int cnt)
{
    if(cnt == n/2)
    {
        vector <int> start, link;

        for(int i=1; i<=n; i++)
        {
            if(visited[i]==0)
            {
                start.push_back(i);
            }
            else{
                link.push_back(i);
            }
        } 

        ans = min(ans, abs(scoreSum(start)-scoreSum(link)));
        return;

    }
    else{
        for(int i= node; i<n; i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                dfs(i+1,cnt+1);
                visited[i]=0;
            }
        }
    }
}



int main()
{
    // input

    cin>>n;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>m_map[i][j];
        }
    }

    //dfs()
    dfs(1,0);

    //output
    cout<<ans<<endl;

    return 0;
}