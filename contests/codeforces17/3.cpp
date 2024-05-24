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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        ll n; cin>>n; 
        vi a(n);
        int ans = 0; 
        for (ll i = 0; i < n; i++) cin>>a[i];
        map<pair<pii, int>, int> gen; 
        map<pii, int> mp1, mp2, mp3; 

        it(i,0,n-2) {
            int val = gen[{{a[i], a[i+1]}, a[i+2]}];
            ans += mp1[{a[i], a[i+1]}] - val;
            ans += mp2[{a[i], a[i+2]}] - val;
            ans += mp3[{a[i+1], a[i+2]}] - val;


            mp1[{a[i], a[i+1]}]++;
            mp2[{a[i], a[i+2]}]++;
            mp3[{a[i+1], a[i+2]}]++;
            gen[{{a[i], a[i+1]}, a[i+2]}]++;
        }
        cout<<ans<<endl; 
        
    }
}