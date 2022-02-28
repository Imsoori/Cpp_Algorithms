#include <iostream>

using namespace std;

int main()
{
   int A[11], B[11];
   int sumA = 0, sumB = 0;
   //int sameResultContinue = 0;
   char lastWinner='D';
   char Winner;


   for (int i = 0; i < 10; i++)
   {
      scanf("%d", &A[i]);
   }
   for (int i = 0; i < 10; i++)
   {
      scanf("%d", &B[i]);
   }

   for (int i = 0; i < 10; i++)
   {
      if (A[i] == B[i])
      {
         //sameResultContinue++;
         sumA += 1;
         sumB += 1;
      }
      else if (A[i] > B[i])
      {
         lastWinner = 'A';
         sumA += 3;
         
      }
      else { //A[i] < B[i]
         lastWinner = 'B';
         sumB += 3;
      }
   }
   printf("%d %d\n", sumA, sumB);
   if (sumA == sumB)
   {
      if (lastWinner == 'A')
      {
         //printf("%d %d\n", sumA, sumB);
         printf("A\n");
      }
      else if (lastWinner == 'B') {
         //printf("%d %d\n", sumA, sumB);
         printf("B\n");
      }
      else
       {
          //printf("%d %d\n", sumA, sumB);
          printf("D\n");
       }
      
   }
   else if (sumA > sumB)
   {
      //printf("%d %d\n", sumA, sumB);
      printf("A\n");
   }
   else {
      //printf("%d %d\n", sumA, sumB);
      printf("B\n");
   }



   return 0;
}
