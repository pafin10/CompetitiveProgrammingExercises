#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        vi a(2*k);
        int mx = 0; 
        for (int i = 0; i< n; i++) {
            int j; cin>>j; 
            a[j % (2*k)]++;
            mx = max(mx, j);
        }
        int cnt = 0;
        for (int i = 0; i < k - 1; i++) cnt += a[i];

        int ans = INT32_MAX;
        for (int l = 0, r = k-1; l < 2 * k; l++, r++) {
            if (r >= 2 * k) r -= 2*k; 

            if (cnt += a[r]; cnt == n) {
                int wait = (r - mx) % (2*k);
                if (wait < 0) wait += 2 * k; 
                ans = min(ans, mx + wait);
            }

            cnt -= a[l];
        }
        if (ans == INT32_MAX) ans = -1;
        cout<<ans<<endl; 
    }
}