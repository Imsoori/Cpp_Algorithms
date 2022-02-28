#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
   int n, k, maxTemp;
   int sum = 0;
   int temperature[100001] = {0,};

   scanf("%d %d", &n, &k);

   for (int i = 0; i < n; i++)
   {
      scanf("%d", &temperature[i]);
   }

   for (int i = 0; i < k; i++)
   {
      sum += temperature[i];
   }
   maxTemp = sum;
   for (int i = k; i < n; i++)
   {
      sum = sum + temperature[i];
      sum = sum - temperature[i - k];
      
      if (sum > maxTemp)
      {
         maxTemp = sum;
      }

      
   }

   printf("%d\n", maxTemp);
   
   return 0;
}
