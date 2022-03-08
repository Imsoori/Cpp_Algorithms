#include <iostream>
#include <vector>
using namespace std;


int main()
{
   char string[30];
   vector <char> v;
   scanf("%s", string);

   for(int i=0; string[i]!='\0'; i++)
   {
      if(string[i]=='(')
      {
         v.push_back('(');
      }
      else{
         if(v.size())
         {
            v.pop_back();
         }
         else{
            printf("NO");
            return 0;
         }
         
      }
   }

   if(v.size()){
      printf("NO");
   }else{
      printf("YES");
   }


   return 0;
}
