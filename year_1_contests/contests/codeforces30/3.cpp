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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, s, m; cin>>n>>s>>m; 
        vector<pii> intervals(n); 
        for (int i = 0; i < n; i++) {
            cin>>intervals[i].ff;
            cin>>intervals[i].ss;
        }
        string ans = "NO";
        for (int i = 0; i < n; i++) {
            if (!i && s <= intervals[i].ff) ans = "YES";
            else if (i) {
                if (intervals[i].ff - intervals[i-1].ss >= s) ans = "YES";
            }
        }
        if (m - intervals[n-1].ss >= s) ans = "YES";
        cout<<ans<<endl; 
    }
}