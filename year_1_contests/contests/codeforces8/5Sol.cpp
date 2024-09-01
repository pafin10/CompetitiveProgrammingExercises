/**
 *    author:  tourist
 *    created: 19.02.2024 09:34:17
**/
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

#ifdef LOCAL
#else
#define debug(...) 42
#endif

// Codeforces solution, reimplement and go through logic manually for several example cases 
// p is the multiplicative factor and (2*k-1) is the position of the card in the current batch 
//(only accessed when card of interest is in current batch)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int x = n;
    int p = 1;
    while (x > 0) {
      int take = x - x / 2;
      if (k <= take) {
        cout << p * (2 * k - 1) << '\n';
        break;
      }
      k -= take;
      p *= 2;
      x /= 2;
    }
  }
  return 0;
}