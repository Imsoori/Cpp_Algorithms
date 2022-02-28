#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
   int n, tmp = 0;
   scanf_s("%d", &n);
   vector<int> arr(n);
   map<int, bool> jollyJumpersDetector;

   for (int i = 0; i < n; i++)
   {
      scanf_s("%d", &arr[i]);

   }

   for (int i = 0; i < n - 1; i++)
   {
   
      if (abs(arr[i] - arr[i + 1]) != 0 && abs(arr[i] - arr[i + 1]) < n)
      {
         jollyJumpersDetector[abs(arr[i] - arr[i + 1])] = true;

      }
      
   }

   if (jollyJumpersDetector.size() == n-1)
   {
      printf("YES\n");
   }
   else{
      printf("NO\n");
   }

   return 0;
}
