#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define INF (ll)1e18
#define MOD (ll)1e8
int main(int argc, char const *argv[]) {
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; t=1;//cin>>t; 
    while(t--) {
        ll n; cin>>n;
        vll a(n), pref(n);
        ll ans = 0, bad_pairs = 0;
        it(i,0,n) cin>>a[i];

        sort(all(a));
        it(i,0,n) ans += a[i] * (n-1);
        it(i,0,n) {
            ll id = lower_bound(all(a), MOD-a[i]) - a.begin();
            ll num = n-id;

            if (a[i]+a[i] >= MOD) num--;
            bad_pairs += num;
        }
        bad_pairs /= 2;
        ans -= bad_pairs * MOD;
        cout<<ans<<endl;
               
    }
}