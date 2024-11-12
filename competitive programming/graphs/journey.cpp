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
const int MAX_N = 100'005;
bool vis[MAX_N];
vector<vi> adj(MAX_N);

double dfs(int u) {
    vis[u] = true; 
    int childCnt = 0;
    double totalLength = 0;

    for (auto v : adj[u]) {
        if (!vis[v]) {
            childCnt++;
            totalLength += dfs(v) + 1;
        }
    }
    if (!childCnt) return 0;
    return totalLength / childCnt;
}

int32_t main() {
    // ifstream cin("journey.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n; cin>>n; 
    for (int i = 0; i < n - 1; i++) {
        int u, v; 
        cin>>u>>v; 
        adj[u].pb(v);
        adj[v].pb(u);
    }
    double ans = dfs(1);
    cout.precision(10);

    cout<<fixed<<ans<<endl;  
}