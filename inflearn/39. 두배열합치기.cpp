#include <iostream>
using namespace std;

int main()
{
   int n, m;
   int pointer1=0, pointer2=0;
   int finishCheck=0;
   int list1[101], list2[101];
   int listSum[202];


   scanf("%d", &n);

   for(int i=0; i<n; i++)
   {
      scanf("%d", &list1[i]);
   }

   scanf("%d", &m);

   for(int i=0; i<m; i++)
   {
      scanf("%d", &list2[i]);
   }

   
   while(finishCheck != n+m)
   {
      if(pointer1<n && pointer2<m)
      {
         if(list1[pointer1]<=list2[pointer2])
         {
               listSum[finishCheck]= list1[pointer1];
               pointer1++;
         }
         else{
               listSum[finishCheck] = list2[pointer2];
               pointer2++;
         }
      }
      else if(pointer1>=n && pointer2<m)
      {
          listSum[finishCheck] = list2[pointer2];
          pointer2++;
      }
      else if(pointer2>=m && pointer1<n)
      {
         listSum[finishCheck]= list1[pointer1];
         pointer1++;
      }
      finishCheck++;
   }
   
      
  
   for(int i=0; i< n+m; i++)
   {
      printf("%d ", listSum[i]);
   }

   return 0;
}