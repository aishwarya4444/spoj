#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
  int i, j, count, l, w, N, T;
  vector<pair<int, int> > sticks;
  vector<bool> visited;
  cin>>T;
  while(T--) {
    count = 0;
    sticks.clear();
    visited.clear();
    cin>>N;
    while(N--) {
      cin>>l>>w;
      visited.push_back(false);
      sticks.push_back(make_pair(l,w));
    }
    sort(sticks.begin(), sticks.end());
    N = visited.size();
    for(i=0; i<N; i++) {
      if(!visited[i]) {
        w = sticks[i].second;
        visited[i] = true;
        for(j=i+1; j<N; j++) {
          if(!visited[j] && sticks[j].second>=w) {
            visited[j] = true;
            w = sticks[j].second;
          }
        }
        count++;
      }
    }
    cout<<count<<'\n';
  }
  return 0;
}
