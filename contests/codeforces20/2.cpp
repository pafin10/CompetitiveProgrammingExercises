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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vll a(n), b(n+1);
        it(i,0,n) cin>>a[i];
        it(i,0,n+1) cin>>b[i];
        ll ans = 0;
        bool passed = false; 
        ll last = b[n];
        ll diffLast = (ll) 10e9 + 1;

        it(i,0,n) {
            ll diff = abs(a[i] - b[i]);
            if (a[i] > b[n] && b[n] > b[i]) passed = true;
            if (a[i] < b[n] && b[n] < b[i]) passed = true;
            ans += diff;
            diffLast = min(diffLast, min(abs(a[i] - last), abs(b[i] - last)));
        }
        if (passed) ans++;
        else ans += diffLast + 1;
        cout<<ans<<endl; 
    }
}