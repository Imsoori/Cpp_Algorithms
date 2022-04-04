//미로탐색;인접행렬

#include <iostream>
#include <vector>
using namespace std;

string map[101];
int visited[101][101]={0,};
int n,m,minLevel=2147000000;
int res=1;
int dx[4]={0,1,0,-1}; //NESW
int dy[4]={1,0,-1,0};

void DFS(int x, int y, int level)
{
   int nx, ny;
   if(x == m-1 && y == n-1)
   {
      if(minLevel>level)
      {
         minLevel=level;
         return;
      }
   }
   else{
      for(int i=0; i<4; i++)
      {
         nx = x + dx[i];
         ny = y + dy[i];

         if(nx>m-1 || nx<0 ||ny<0 || ny>n-1)
            continue;
         if(map[ny][nx]=='1' && visited[ny][nx]==0)
         {
            visited[ny][nx] = 1;
            DFS(nx,ny,level+1);
            visited[ny][nx] = 0;
         } 
      }
   }
}

int main()
{
   scanf("%d %d", &n,&m);
   for(int i=0; i<n; i++)
   { 
      cin>>map[i];
   
   }
   visited[0][0]=1;
   DFS(0,0,1);

   printf("%d\n", minLevel);

   return 0;
}