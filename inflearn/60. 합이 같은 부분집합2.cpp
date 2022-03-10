#include <iostream>
using namespace std;

int numbers[11];
int n;
int total=0;
bool result = false;


void DFS(int level, int sum)
{
   if(result==true) return;
   if(sum>(total/2)) return;
   if(level == n+1){
      if(sum ==(total-sum)){
         result=true;
      }
   }
   else{
      DFS(level+1, sum+numbers[level]);
      DFS(level+1, sum);
   }
}

int main()
{
   
   scanf("%d", &n);

   for(int i=1; i<=n; i++)
   {
      scanf("%d", &numbers[i]);
      total += numbers[i];
   }

   DFS(1,0); //level, 원소의 합

   if(result){printf("YES");}
   else{printf("NO");}

   return 0;
}
