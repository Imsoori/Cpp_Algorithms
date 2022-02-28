#include <iostream>
#include <queue>
using namespace std;


char gameOutput(int gameA, int gameB)
{
   char result;
  
  if(gameA == gameB)
  {
     return 'D';
  }
  else{
     if(gameA==1)
     {
        if(gameB==2)
        {
           result ='B';
        }
        else{
           result ='A';
        }
     }
     else if(gameA==2)
     {
         if(gameB==1)
         {
            result ='A';
         }
         else{
            result ='B';
         }
     }
     else{//gameA=3
        if(gameB==1)
         {
            result ='B';
         }
         else{
            result ='A';
         }

     }
  }
   return result;
}


int main()
{
   std::ios::sync_with_stdio(false);

   int n, tmpInput;
   queue <int> gameA, gameB;

   cin>>n;

   // 1. input
   for(int cnt=0; cnt<2; cnt++)
   {
      for(int i=0; i<n; i++)
      {
         cin>>tmpInput;
         if(cnt==0)
         {
            gameA.push(tmpInput);
            //cout<<"gameA"<<tmpInput<<endl;
         }
         else{
            gameB.push(tmpInput);
            //cout<<"gameB"<<tmpInput<<endl;
         }
      }
   }

   for(int i=0; i<n;i++)
   {
      cout<<gameOutput(gameA.front(),gameB.front())<<endl;
      gameA.pop();
      gameB.pop();

   }


   return 0;
   
}
