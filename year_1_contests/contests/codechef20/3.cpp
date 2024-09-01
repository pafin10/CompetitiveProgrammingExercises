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
#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t; 

    while (t--) {
        int n; 
        cin >> n; 
        vi a(n);
        map<int, vi> m; // Store indices of values that satisfy the condition

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));

        vector<pii> ranges; 

        for (int i = 0; i < n; i++) {
            if (m.find(a[i]) != m.end()) {
                for (int j : m[a[i]]) {
                    ranges.pb({min(i, j), max(i, j)});
                }
            }
        }
        if (sz(ranges) == 0){
            cout<<0<<endl; 
            continue;
        }
        sort(all(ranges));
        
        int count = 0;
        int lastEnd = -1;
        vi lengths;

        for (const auto& range : ranges) {
            if (range.ff > lastEnd) {
                lengths.pb(range.ff - lastEnd - 1);
                lastEnd = range.ss;
                count++;
            } else {
                lastEnd = max(lastEnd, range.ss);
            }
        }
        
        if (count == 1) lengths.pb(ranges[0].ss - ranges[0].ff + 1);

        int cnt = 0;
        for (auto& length : lengths) {
            cnt += length * (length + 1) / 2;
        }
        int ans = n * (n+1) / 2 - cnt; 
        cout << ans << endl;
    }

    return 0;
}
