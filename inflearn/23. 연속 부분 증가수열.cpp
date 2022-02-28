#include <iostream>

using namespace std;

int main()
{
   int n, cnt = 1, maxCnt=0;
   scanf("%d", &n);

   vector<int> arr(n);

   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }

   for (int i = 0; i < n-1; i++)
   {
      if (arr[i] <= arr[i + 1])
      {
         cnt++;
      }
      else {
         cnt = 1;
      }

      if (cnt > maxCnt)
      {
         maxCnt = cnt;
      }
   }
   
   printf("%d\n", maxCnt);

   
   return 0;
}
