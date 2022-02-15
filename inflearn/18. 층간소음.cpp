#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int main() {

   int n, m, tmp, cnt = 0, max=-1;
   bool flag=false;
   queue <int> noise;
   scanf("%d %d", &n, &m);

   for (int i = 0; i < n; i++)
   {
      scanf("%d", &tmp);
      noise.push(tmp);
   }
   


   while (!noise.empty())
   {
      if (noise.front() > m)
      {
         flag = true;
         cnt++;      
      }
      else {
      
         if (max < cnt)
         {
            max = cnt;
         }
         cnt = 0;
      }

      noise.pop();
   }

   if (!flag) {
      cout << "-1";
   }
   else
   {
      if (max < cnt)
      {
         max = cnt;
      }
      cout << max ;
   }

   return 0;
}