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
    // TOMORROW OR TOMORROW
    ifstream cin("formingTriangles.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        it(i,0,n) cin>>a[i];
        sort(all(a));
        ll numerator = n * (n-1) * (n-2);
        ll ans = numerator / 6;
        ll cnt = 0; 

        map<ll, ll> m; 
        for (auto& x: a) m[x]++;
        int k = sz(m);
        ll sum = 0;
        for (auto &p : m) {
            if (cnt >= 2) {
                ll sub = p.ss * sum * (sum-1) / 2;
                ans -= sub;
            } 
            sum += p.ss;
            cnt++;
        }
        cout<<ans<<endl; 
    }
}