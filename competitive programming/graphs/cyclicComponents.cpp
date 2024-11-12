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
bool used[2*MAX_N];
vector<vi> g(2*MAX_N); 
vi deg(2*MAX_N, 0);
vi components; 

void dfs(int v) {
    used[v] = true;
    components.pb(v);

    for (auto to: g[v])
        if (!used[to]) {
            dfs(to);
        }
}

int32_t main() {
    //ifstream cin("cyclicComponents.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; 
    cin>>n>>m;

    for (int i = 0; i < m; i++) {
        int x, y; cin>>x>>y;
        x--; y--; 

        g[x].pb(y);
        g[y].pb(x);
        deg[x]++;
        deg[y]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            components.clear();
            dfs(i);

            bool ok = true;
            for (auto node : components) ok &= (deg[node] == 2);
            if (ok) ans++;  
        }
        
    }
    cout<<ans<<endl; 
    
}