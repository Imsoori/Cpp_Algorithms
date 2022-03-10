#include <iostream>
using namespace std;

int numbers[11];
int n,m;
int cnt=0;

void DFS(int level, int sum)
{
   if(level == n+1){
      if(sum ==m){
         cnt++;
        // return;
      }
      
   }
   else{
      DFS(level+1, sum+numbers[level]);
      DFS(level+1, sum);
      DFS(level+1, sum-numbers[level]);
   }
}

int main()
{
   
   scanf("%d %d", &n, &m);

   for(int i=1; i<=n; i++)
   {
      scanf("%d", &numbers[i]);
   }

   DFS(1,0); //level, 원소의 합

   if(cnt){printf("%d",cnt);}
   else{printf("-1");}

   return 0;
}
