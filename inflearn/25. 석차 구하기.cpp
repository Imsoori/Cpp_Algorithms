#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int n,tmp;
   scanf_s("%d", &n);

   vector <int> order(n);
   vector <int> grade(n);

   for (int i = 0; i < n; i++)
   {
      scanf_s("%d", &grade[i]);
      
   }

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (grade[i] < grade[j])
         {
            order[i]++;
         }
      }
   }

   for (int i = 0; i < n; i++)
   {
      printf("%d ", order[i]+1);
   }

   return 0;
}
