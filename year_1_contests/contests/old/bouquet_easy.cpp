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
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("bouquet_easy.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        vi a(n), dp(n-1);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int curr = a[0], ans = a[0] <= m ? a[0] : 0;

        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) curr += a[i];
            else curr = a[i];
            if (curr <= m) ans = max(ans, curr);
        }
        curr = a[0];
        int last = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1]) curr += a[i];
            else if (a[i] == a[i-1] + 1) {
                last = curr; 
                curr = a[i];
            }
            else {
                last = 0;
                curr = a[i];
            }
            if (last + curr <= m) ans = max(ans, last + curr);
            else if (last + curr - a[i] + 1 <= m) ans = max(ans, last + curr - a[i] + 1);
        }
        cout<<ans<<endl; 
    }
}