// https://www.spoj.com/problems/EDIST/

#include<iostream>
#include<cstring>
using namespace std;
int dp[2001][2001];
int main(void )
{
   int N, R, C, r, c;
   string a, b;
   cin>>N;
   while(N--)
   {
      cin>>a>>b;
      R=a.size();
      C=b.size();
      for(r=0;r<=R;r++)dp[r][0]=r;
      for(c=1;c<=C;c++)dp[0][c]=c;
      for(r=1;r<=R;r++)
      {
         for(c=1;c<=C;c++)
         {
            if(a[r-1]==b[c-1])dp[r][c]=dp[r-1][c-1];
            else dp[r][c]=1+min(dp[r-1][c-1],min(dp[r][c-1],dp[r-1][c]));
         }
      }
      cout<<dp[R][C]<<endl;
   }
   return 0;
}
