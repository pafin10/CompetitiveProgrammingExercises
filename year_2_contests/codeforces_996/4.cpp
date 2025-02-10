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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;

int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        double n, k, l; cin>>n>>k>>l; 
        vector<int> a(n);

        for (auto& i: a) cin>>i;

        double d = 0;
        double time = a[0];
        double last_pt = 0;

        for (int i = 1; i < n; i++) {
            double this_pt = min(l, min(a[i] + time, 
            max(last_pt + k, (a[i] - time + last_pt + k) / 2.0)));

            time += max(0.0, this_pt - last_pt - k);
            d += min(k, this_pt - last_pt);
            last_pt = this_pt;
        } 
        d += min(k, l - last_pt);
        int ans = (int) round(2 * (a[0] + l - d));
        
        cout<<ans<<endl; 

    }
}