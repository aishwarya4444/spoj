// https://abitofcs.blogspot.com/2014/10/spoj-nested-dolls-mdolls.html

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const pair<int, int> &l, const pair<int, int> &r) {
  if(l.first == r.first) {
    return l.second > r.second;
  } else {
    return l.first < r.first;
  }
}

int main(void ) {
  int i, l, r, m, w, h, T, N;
  vector<pair<int, int> > dolls, result;
  cin>>T;
  while(T--) {
    cin>>N;
    dolls.clear();
    result.clear();
    while(N--) {
      cin>>w>>h;
      dolls.push_back(make_pair(w,h));
    }
    N = dolls.size();
    sort(dolls.begin(), dolls.end(), compare);
    result.push_back(dolls[N-1]);
    for(i=N-2; i>=0; i--) {
      l = 0;
      r = result.size() - 1;
      while(l<=r) {
        m = (l+r)/2;
        if(result[m].first==dolls[i].first || result[m].second<=dolls[i].second) {
          l = m+1;
        } else {
          r = m-1;
        }
      }
      if(l==result.size()) {
        result.push_back(dolls[i]);
      } else {
        result[l].second = dolls[i].second;
        result[l].first = dolls[i].first;
      }
    }
    cout<<result.size()<<'\n';
  }
  return 0;
}
