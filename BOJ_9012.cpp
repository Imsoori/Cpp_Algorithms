#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


string checkVPS(char m_str[])
{
   vector <char> v;
   for(int i=0; m_str[i]!='\0'; i++)
      {
         if(m_str[i]=='(')
         {
            v.push_back('(');
         }
         else{
            if(v.size())
            {
               v.pop_back();
            }
            else{
               return "NO";
            }
            
         }
      }

      if(v.size()){
         return "NO";
      }else{
         return "YES";
      }
}


int main()
{
   char m_str[51];
   int n;
   scanf("%d", &n);
   queue <string> res;
   
  

   for(int x=0; x<n; x++)
   {
       scanf("%s", m_str);
       res.push(checkVPS(m_str));
      
   }

   for(int i=0; i<n; i++)
   {
      printf("%s\n", res.front().c_str());
      res.pop();
   }


   return 0;
}
