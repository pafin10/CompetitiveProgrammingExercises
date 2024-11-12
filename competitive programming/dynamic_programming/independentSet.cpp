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


using namespace std;
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
const int MAX_N = 100'005, mod = 1e9 + 7;
vector<int> g[MAX_N];
int dp[MAX_N][2];


void dfs(int u, int par) {
    dp[u][0] = 1, dp[u][1] = 1; 

    for (auto w : g[u]) {
        if (w == par) continue; 
        
        dfs(w, u);
        
        dp[u][0] = 1LL * dp[u][0] * (dp[w][1] + dp[w][0]) % mod;
        dp[u][1] = 1LL * dp[u][1] * dp[w][0] % mod;
    }

}
int32_t main() {
    // ifstream cin("independentSet.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v; 
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1);
    
    cout<<(dp[0][0] + dp[0][1]) % mod<<endl; 
}