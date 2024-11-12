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
#define int long long

const int MAX_N = 100'005;
int parent[2 * MAX_N], rnk[2 * MAX_N];

const int C = 10 + 1; 
int dp[2 * MAX_N][C], id[2 * MAX_N][C];
int start_cnt[2 * MAX_N][C], end_cnt[2 * MAX_N][C];


void make_set(int v) {
    parent[v] = v; 
    rnk[v] = 1;
}

int find_set(int a) {
    if (parent[a] == a)
        return a; 
    return parent[a] = find_set(parent[a]);
}

void union_sets(int a, int b) {
    a = find_set(a); 
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a; 
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}

void reset(int n) {
    for (int i = 1; i <= n; i++) {
        make_set(i);
        for (int j = 1; j < C; j++) {
            dp[i][j] = start_cnt[i][j] = end_cnt[i][j] = 0; 
            id[i][j] = i; 
        }
    }
}

void solve() {
    int n, m, a, d, k; 
    cin>>n>>m;
    reset(n);

    for (int i = 0; i < m; i++) {
        cin>>a>>d>>k; 
        start_cnt[a][d]++;
        end_cnt[a + k * d][d]++;
    }

    for (int j = 1; j <= n; j++) 
        for (int w = 1; w < C; w++) {
            dp[j][w] = start_cnt[j][w] - end_cnt[j][w];
            if (j - w < 1) continue; 
              
            if (dp[j - w][w]) {
                union_sets(j, id[j - w][w]);
                dp[j][w] += dp[j - w][w];
                id[j][w] = id[j - w][w];
            }
        }

    int ans = 0; 
    for (int i = 1; i <= n; i++) {
        if (find_set(i) == i) ans++;
    }

    cout<<ans<<endl; 
    
}

int32_t main() {
    // ifstream file("connectTheDots.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; /*file>>t;*/ cin>>t; 
    while(t--) {
        solve();
    }
}