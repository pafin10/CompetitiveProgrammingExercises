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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        string s; cin>>s; 
        string p; cin>>p; 
        p = '_' + p;

        map<char, char> m; 
        for (int i = 0; i < n; i++) {
            int j; 
            if (!m[s[i]]) {
                for (j = 1; j < p.size(); j++) {
                    if (p[j] == s[i]) break; 
                }
                m[s[i]] = p[27 - j];
            }
        }

        vector<vi> dp(n, vi(2, 1e9)); //pos, modified or not
        dp[0][1] = 1;
        dp[0][0] = 0; 

        for (int i = 1; i < n; i++) {
            if (s[i] >= s[i - 1]) {
                dp[i][0] = dp[i - 1][0];
            }
            if (s[i] >= m[s[i - 1]]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            }
            if (m[s[i]] >= s[i - 1]) {
                dp[i][1] = dp[i - 1][0] + 1;
            }
            if (m[s[i]] >= m[s[i - 1]]) {
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
            }
        }
        int ans = min(dp[n-1][0], dp[n - 1][1]);
        cout<<((ans == 1e9) ? -1 : ans)<<endl; 
    }
}