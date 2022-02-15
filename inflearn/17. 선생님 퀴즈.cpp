#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool checkSum(int num, int sum)
{
   int cmp = num * (num + 1) / 2;
   if (sum == cmp)
   {
      return true;
   }
   else {
      return false;
   }
}

int main() {

   int n, num, sum,tmp;
   bool flag=false;
   queue <bool> quiz;
   scanf("%d", &n);


   for (int i = 0; i < n; i++)
   {
      scanf("%d %d", &num, &sum);
      quiz.push(checkSum(num,sum));
   }
   
   while (!quiz.empty())
   {
      if (quiz.front())
      {
         printf("YES\n");
      }
      else {
         printf("NO\n");
      }

      quiz.pop();
   }
   
   return 0;
}