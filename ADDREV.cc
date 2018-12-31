// ADDREV - Adding Reversed Numbers

#include<iostream>
using namespace std;

int main(void )
{
   int N, a, b, A, B, x, sum;
   cin>>N;
   while(N--)
   {
      cin>>a>>b;
      x=0,sum=0,A=1,B=1;
      while(a/A>9)A*=10;
      while(b/B>9)B*=10;
      while(a || b)
      {
         if(a)sum+=a/A,a%=A,A/=10;
         if(b)sum+=b/B,b%=B,B/=10;
         x=10*x+(sum%10);
         sum/=10;
      }
      if(sum)x=10*x+sum;
      cout<<x<<endl;
   }
}
