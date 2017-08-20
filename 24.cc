#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

typedef short int SI;

void factorial(SI n)
{
   string res("1"), num("0123456789");
   if(n<2)
   {
      cout<<res<<endl;
      return;
   }
   size_t prod, carry;
   for(n;n>1;n--)
   {
      carry=0;
      for(SI i=res.size()-1;i>=0;i--)
      {
         prod=(res[i]-48)*n+carry;
         res[i]=num[prod%10];
         carry=prod/10;
      }
      while(carry)
      {
         res=num[carry%10]+res;
         carry/=10;
      }
   }
   cout<<res<<endl;
}

int main(void )
{
   SI t, n;
   cin>>t;
   while(t--)
   {
      cin>>n;
      factorial(n);
   }
   return 0;
}
