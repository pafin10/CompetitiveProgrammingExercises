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

int32_t main() {
    // ifstream cin("mortalKombatTower.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        for (auto& i : a) cin>>i;

        if (n == 1) {
            cout<<(a[0] ? 1 : 0)<<endl; 
            continue;
        }
        vi dp(n+1, 0);
        dp[0] = a[0] ? 1 : 0;; 

        bool frd = a[1] ? 0 : 1;
        int cnt = frd ? 1 : 0;

        for(int i = 1; i < n; i++) {
            if (cnt == 2) {
                frd = !frd;
                cnt = 0; 
            }
            else if ((cnt < 2 && frd && a[i]) || (cnt < 2 && !frd && !a[i])) {
                frd = !frd;
                cnt = 0; 
            }

            if (frd) {
                if (a[i]) dp[i] = dp[i-1] + 1;
                else dp[i] = dp[i-1];
                cnt++;
            }
            else {
                dp[i] = dp[i-1];
                cnt++;
            }
        }

        cout<<dp[n-1]<<endl; 
    }
}