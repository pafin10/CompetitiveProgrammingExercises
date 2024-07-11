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

int32_t main() {
    //ifstream cin("makeAlmostEqualWithMod.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; 
        cin>>n; 
        ll maxi = 0; 
        vll a(n); bool even = false, odd = false; 
        it(i,0,n) {cin>>a[i]; (a[i]%2) == 0 ? even = true : odd = true; if (a[i]>maxi) maxi = a[i];}
        if (odd & even) {cout<<2<<endl; continue;}

        set<ll> b;
        ll ans = 0;
        for (ll i = 2; i < maxi; i*=2) {
            for (auto& x : a) {
                b.insert(x % i);
                if (sz(b) > 2) break; 
            }
            if (sz(b) == 2) {ans = i; break;}
            else b.clear();   
        }
        if (ans == 0) ans = maxi+1;
        cout<<ans<<endl; 
     
    }
}