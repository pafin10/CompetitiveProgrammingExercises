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
#include <deque>
#include <functional>
#include <stack>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
#define int long long
constexpr int MAXN = 2005;
constexpr int INF = 1E9;  
constexpr int MOD = 998244353;

int dp[MAXN][MAXN][2];
int pref[MAXN][MAXN][2];
bool wall[MAXN][MAXN];
int n, m, d; 

int get_sum(int x, int L, int R, int f) {
    int res = pref[x][R][f];
    if (L > 0)
        res = (res - pref[x][L-1][f] + MOD) % MOD;
    return res;
}

int get(int i, int j, int f) {
    if (!wall[i][j]) return 0; 
    int res = 0; 
    if (i == n - 1) res++;

    if (f == 0) {
        res += get_sum(i, max(j - d, 0LL), min(j + d, m - 1), 1);
        res -= dp[i][j][1];
    }
    if (i < n - 1) {
        res += get_sum(i + 1, max(0LL, j - d + 1), min(j + d - 1, m - 1), 0);
    }
    return res % MOD; 

}


int32_t main() {    
    // ifstream cin("6.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        cin>>n>>m>>d; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x; cin>>x; 
                wall[i][j] = ((x == 'X') ? 1 : 0);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int f = 1; f >= 0; f--) {
                for (int j = 0; j < m; j++) {
                    pref[i][j][f] = dp[i][j][f] = get(i, j, f);
                }
                for (int j = 1; j < m; j++) {
                    pref[i][j][f] += pref[i][j - 1][f];
                }
            }
        }



        int ans = 0;
        for (int j = 0; j < m; j++) ans += dp[0][j][0] % MOD;
        cout<< ans % MOD <<endl; 
    }
}