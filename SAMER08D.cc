// https://www.spoj.com/problems/SAMER08D/
// https://discuss.codechef.com/questions/89981/help-with-problem-samer08d-dna-sequences
// https://ideone.com/RAz7ZZ

#include<iostream>
#include<cstring>
using namespace std;

int main(void) {
	string X, Y;
	size_t x, y, lX, lY, k, K, dp[1002][1002];
	while(true) {
		cin>> K;
		if(!K) {
			break;
		}
		cin>>X;
		cin>>Y;
		lX=X.size();
		lY=Y.size();
		for(x=0; x<=lX; x++) {
			for(y=0; y<=lY; y++) {
				dp[x][y] = 0;
				if(!x || !y) {
					continue;
				}
				k=1;
				while(x>=k && y>=k && X[x-k]==Y[y-k]) {
					if(k>=K) {
						dp[x][y] = max(dp[x][y], dp[x-k][y-k] + k);
					}
					k++;
				}
				dp[x][y]=max(dp[x][y], max(dp[x-1][y], dp[x][y-1]));
			}
		}
		cout<<dp[lX][lY]<<'\n';
	}
	return 0;
}
