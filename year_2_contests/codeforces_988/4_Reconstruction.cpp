#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
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
const int INF = 1E9;


int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m, L;
        cin >> n >> m >> L;
        vector<pii> hurdles(n), power_ups(m);

        for (int i = 0; i < n; i++) {
            cin >> hurdles[i].ff >> hurdles[i].ss;
        }
        for (int i = 0; i < m; i++) {
            cin >> power_ups[i].ff >> power_ups[i].ss;
        }

        multiset<int> ms; // use multiset for ordered set and multiple occurences
        int k = 1; 
        int ans = 0; 
        int ptr = 0;

        for (int i = 0; i < n; i++) {
            // check region up to current hurdle
            while (ptr < m && power_ups[ptr].ff < hurdles[i].ff) {
                ms.insert(power_ups[ptr++].ss);
            }
            // use power ups to jump over hurdle, starting from the biggest
            while (k < hurdles[i].ss - hurdles[i].ff + 2) {
                if (ms.empty()) {
                    ans = -1; 
                    break; 
                }
                k += *prev(ms.end());
                ans++;
                ms.erase(prev(ms.end()));
            }
            if (ans == -1) break; 
        }
        cout<<ans<<endl; 

    }
}