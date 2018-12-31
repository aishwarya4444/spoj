// https://www.spoj.com/problems/FCTRL/

#include<iostream>
using namespace std;
int main(void )
{
   long long t, n;
   size_t count;
   cin>>t;
   while(t--)
   {
      cin>>n;
      count=0;
      while(n)
      {
         count+=n/5;
         n/=5;
      }
      cout<<count<<endl;
   }
   return 0;
}
