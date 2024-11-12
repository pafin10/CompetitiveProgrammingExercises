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
const int MAX_N = 100'005, inf = 1e9;
const int N = 33, M = 33, K = 55;
int dp[N][M][K];

void fill_dp() {

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            for (int l = 0; l < K; l++) {
                if (i * j < l) {
                    dp[i][j][l] = inf; 
                    continue; 
                }

                if (l == 0 || l == i * j) {
                    dp[i][j][l] = 0; 
                    continue; 
                }

                dp[i][j][l] = inf; 

                for (int i1 = 1; i1 < i; i1++) 
                    for (int l1 = 0; l1 <= l; l1++) {
                        int i2 = i - i1, l2 = l - l1; 
                        dp[i][j][l] = min(dp[i][j][l], dp[i1][j][l1] + dp[i2][j][l2] + j * j);
                    }
                
                for (int j1 = 1; j1 < j; j1++) 
                    for (int l1 = 0; l1 <= l; l1++) {
                        int j2 = j - j1, l2 = l - l1; 
                        dp[i][j][l] = min(dp[i][j][l], dp[i][j1][l1] + dp[i][j2][l2] + i * i);
                    }
            }
}

int32_t main() {
    // ifstream cin("chocolateBar.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_dp();
    int t; cin>>t; 

    while(t--) {
        int n, m, k; 
        cin>>n>>m>>k;

        cout<<dp[n][m][k]<<endl; 
    }
}