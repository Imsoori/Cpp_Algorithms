#include <iostream>
using namespace std;

int n;
int visited[11];

void DFS(int level)
{
   if(level == n+1)
   {
      for(int i=1; i<=n; i++)
      {
         if(visited[i]==1) printf("%d ",i);
      }
      puts("");
   }
   else{
      visited[level]=1;
      DFS(level+1);
      visited[level]=0;
      DFS(level+1);
   }
}

int main()
{
   scanf("%d", &n);
   DFS(1);
   return 0;
}
