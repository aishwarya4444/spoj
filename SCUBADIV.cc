// https://www.spoj.com/problems/SCUBADIV/
// https://abitofcs.blogspot.com/2014/10/a-bit-of-dp-spoj-scubadiv.html
// https://github.com/fazlerahmanejazi/SPOJ/blob/master/SCUBADIV%20-%20Scuba%20diver.cpp
// https://github.com/prajogotio/spoj/blob/master/SCUBADIV/b.cpp

#include<iostream>
#define INF 123456789
using namespace std;

// oxygen nitrogen weight
int cylinders[1001][3];
int dp[1001][22][80];

int solve(int N, int oxygen, int nitrogen) {
  int i, j, k;
  for(k=0; k<=N; k++) {
    for(i=0; i<22; i++) {
      for(j=0; j<80; j++) {
        if(k==0) {
          dp[k][i][j] = INF;
          if(i==0 && j==0) {
            dp[k][i][j] = 0;
          }
        } else {
          dp[k][i][j] = min(dp[k-1][i][j], cylinders[k][2] + dp[k-1][max(0, i-cylinders[k][0])][max(0, j-cylinders[k][1])]);
        }
      }
    }
  }
  return dp[N][oxygen][nitrogen];
}

int main(void) {
	int oxygen, nitrogen, i, N, T;
  cin>>T;
  while(T--) {
    cin>>oxygen>>nitrogen;
    cin>>N;
    for(i=1; i<=N; i++) {
      cin>>cylinders[i][0]>>cylinders[i][1]>>cylinders[i][2];
    }
    cout<<solve(N, oxygen, nitrogen)<<'\n';
  }
  return 0;
}
