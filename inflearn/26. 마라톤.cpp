#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
   int n,cnt=0;
   scanf_s("%d", &n);

   vector <int> runnerValue(n);
   vector <int> maxWinner(n);

   for (int i = 0; i < n; i++)
   {
      scanf_s("%d", &runnerValue[i]);
   }

   for (int idx = runnerValue.size() - 1; idx >= 0; idx--)
   {
      cnt = 0;

      for (int j = 0; j <idx; j++)
      {
         if (runnerValue[j] < runnerValue[idx])
         {
            cnt++;
         }
      }

      maxWinner[idx] = (idx+1)-cnt;
   }

   for (int i = 0; i < n; i++)
   {
      printf("%d ", maxWinner[i]);
   }
   
   return 0;
}
