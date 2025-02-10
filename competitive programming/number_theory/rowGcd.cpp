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
#include <deque>


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
    // ifstream cin("rowGcd.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        vector<int> a(n), b(m);

        for (auto& i: a) cin>>i; 
        for (auto& i : b) cin>>i; 
        
        if (n == 1) {
            for (int i = 0; i < m; i++) cout<<(b[i] + a[0])<<" ";
            cout<<endl; 
            continue;
        }

        int d = abs(a[1] - a[0]); 
        for (int i = 1; i < n; i++) {
            d = gcd(d, abs(a[i] - a[0]));
        }
        vector<int> ans; 
        for (int i = 0; i < m; i++) {
            ans.push_back(gcd(d, a[0] + b[i]));
        }
        for(auto & e: ans) cout<<e<<" ";
        cout<<endl; 
    }
}