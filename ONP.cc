// http://www.spoj.com/problems/ONP/

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main(void )
{
   string src;
   stack<char> sym;
   size_t i, t;
   cin>>t;
   while(t--)
   {
      cin>>src;
      string des;
      for(i=0;src[i];i++)
      {
         if(src[i]!='(')
         {
            if(src[i]==')')
            {
               des+=sym.top();
               sym.pop();
            }
            else if(src[i]=='+' || src[i]=='-' || src[i]=='*' || src[i]=='/' || src[i]=='^' )
            {
               sym.push(src[i]);
            }
            else
            {
               des+=src[i];
            }
         }
      }
      while(sym.size())
      {
         des+=sym.top();
         sym.pop();
      }
      cout<<des<<endl;
   }
   return 0;
}
