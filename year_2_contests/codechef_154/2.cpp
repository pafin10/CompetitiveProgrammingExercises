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
#include <array>


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
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        vi a(n);

        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }

        if (n == 1) {
            cout<<((a[0] == k) ? 0 : 1)<<endl; 
            continue;
        }
        
        int ans = 0; 
        for (int i = 0; i < n; i++) {
            if (a[i] == k) continue;
            
            ans++;
            while (i < n - 1 && a[i] == a[i+1]) i++;
            
            int add = 0;
            while (i < n && gcd(k, a[i]) == k) {
                add = 1; 
                i++;
            }
            if (i < n) ans += add;
        }
        if (ans >= 2) cout<<2<<endl; 
        else cout<<ans<<endl; 

    }
}