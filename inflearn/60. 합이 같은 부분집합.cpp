#include <iostream>
using namespace std;

int numbers[11];
int visited[11];
int n;
int checkSum=0;
bool result = false;

void DFS(int level)
{
   if(level == n+1)
   {
      for(int i=1; i<=n; i++)
      {
         if(visited[i]==1){
            checkSum += numbers[i];
         }
         else{
            checkSum -= numbers[i];
         }
      }
      if(checkSum==0)
      {
         result = true;
         return;
      }else{
         checkSum=0;
      }
      
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

   for(int i=1; i<=n; i++)
   {
      scanf("%d", &numbers[i]);
   }

   DFS(1);

   if(result){printf("YES");}
   else{printf("NO");}
   return 0;
}
