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

int solve(int n, int c, vi &a) {
    vector<pair<int, pii>> edges;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.pb({a[i] * a[j], {i, j}});
        }
    }
    int totalCost = 0;
    sort(all(edges));

    vi del; 
    for (auto& e : edges) {
        if (totalCost + e.ff > c) break; 
        if (e.ss.ff == 0) {
            totalCost += e.ff;
            del.pb(e.ss.ss);
        }
    }
    
    vi allCosts;
    int costs = 0; 
    map<int, vi> ignoreBridges;

    it(i,0,sz(del)) {
        it(j,i+1, sz(del)) {
            ignoreBridges[del[i]].pb(del[j]);
        }
    }

    for (auto&d : del) {
        costs = 0;
        for (auto& e: edges) {
            if (e.ss.ff == d) {
                bool skip = false; 
                if (e.ss.ff < sz(ignoreBridges)) {
                    it(i,0,sz(ignoreBridges[e.ss.ff])) {
                        if (ignoreBridges[e.ss.ff][i] == e.ss.ss) {
                            skip = true; 
                            break; 
                        }
                    }
                }
                
                if (skip) continue;
                costs += e.ff;
            }
        }
        if (costs) allCosts.pb(costs);
    }
    sort(all(allCosts));   
    int j = 0;
    while (j < sz(allCosts) && allCosts[j] + totalCost <= c) {
        totalCost += allCosts[j];
        j++;
    }
    assert(totalCost <= c);
    return max(1LL, n-j); 
}
int32_t main() {
    ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, c; cin>>n>>c;
        vi a(n); it(i,0,n) cin>>a[i];
        int ans = solve(n,c,a);
        cout<<ans<<endl; 
    }
}