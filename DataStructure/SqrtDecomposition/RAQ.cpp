#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  const int sqrtN = 512;
  const ll inf = (1LL<<31)-1;
  int n, q;
  cin >> n >> q;
  int bucket_sz = (n+sqrtN-1)/sqrtN;
  vector<ll> a(n, 0);
  vector<ll> bucketAdd(bucket_sz, 0);
  auto update = [&](int s, int t, int x) {
    for(int i = 0; i < bucket_sz; ++i) {
      int l = i*sqrtN, r = (i+1)*sqrtN;
      if(r <= s || t <= l) continue;
      if(s <= l && r <= t) bucketAdd[i] += x;
      else {
	for(int j = max(s, l); j < min(t, r); ++j) {
	  a[j] += x;
	}
      }
    }
  };
  auto get = [&](int k)->ll{
    return a[k]+bucketAdd[k/sqrtN];
  };
  while(q--) {
    int t;
    cin >> t;
    if(t == 0) {
      ll s, t, x;
      cin >> s >> t >> x;
      update(s-1, t, x);
    } else {
      int k;
      cin >> k;
      cout << get(k-1) << endl;
    }
  }

  return 0;
}
