// https://www.spoj.com/problems/MIXTURES/
// https://github.com/fazlerahmanejazi/SPOJ/blob/master/MIXTURES%20-%20Mixtures.cpp
// https://www.youtube.com/watch?v=XHjjIJxnAJY

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> mix;
int dp[101][101];

int total(int l, int r) {
  int sum = 0;
  for(; l<=r; l++) {
    sum += mix[l];
    sum %= 100;
  }
  return sum;
}

int solve(int i, int j) {
  if(i>=j) return 0;
  if(dp[i][j]!=INT_MAX) {
    return dp[i][j];
  }
  for(int k=i; k<=j; k++) {
    dp[i][j] = min(dp[i][j], solve(i,k)+solve(k+1,j)+total(i,k)*total(k+1,j));
  }
  return dp[i][j];
}

void dpReset() {
  int r, c;
  for(r=0; r<101; r++) {
    for(c=0; c<101; c++) {
      dp[r][c] = INT_MAX;
    }
  }
}

int main(void) {
  int mixture, N;
  while(cin>>N) {
    mix.clear();
    dpReset();
    while(N--) {
      cin>>mixture;
      mix.push_back(mixture);
    }
    cout<<solve(0, mix.size()-1)<<'\n';
  }
	return 0;
}
