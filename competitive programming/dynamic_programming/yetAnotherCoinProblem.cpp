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
#include <unordered_set>



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

int32_t main() {
    //ifstream cin("yetAnotherCoinProblem.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    vi dp(31);
    vi coins = {15, 10, 6, 3, 1};

    for (int i = 1; i <= 15; i++) {
        if (find(coins.begin(), coins.end(), i) != coins.end()) dp[i] = 1;
        else if (dp[i-1] == 1 || i == 12 || i == 9 || i == 13) dp[i] = 2;
        else dp[i] = 3;
    }
    for (int i = 16; i <= 30; i++) {
        int k = i - 15; 
        dp[i] = dp[k] + 1;
        k = i;
        int j = 1, cnt = 0;
        while (k > 0) {
            while (coins[j] <= k) {
                k -= coins[j];
                cnt++;
            }
            j++;
        }
        dp[i] = min(dp[i], cnt);
    }

    while(t--) {
        int n; cin>>n; 
        int ans = 0;
        if (n < 30) cout<<dp[n]<<endl; 
        else {
            if (n % 15 == 0) cout<<n/15<<endl;
            else {
                ans = (n - 30) / 15 + 1;
                int k = n - 30;
                while (k % 15 != 0) k++;
                int diff = n-k;
                ans += dp[diff];
                cout<<ans<<endl; 
            }
        }
    }
}