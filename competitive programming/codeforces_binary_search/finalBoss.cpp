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
    // Naive
    // check out again
    ifstream cin("finalBoss.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int h, n; cin>>h>>n; 
        vi a(n), b(n);
        int attackSum = 0;
        it(i,0,n) {cin>>a[i]; attackSum += a[i]; }
        it(i,0,n) cin>>b[i];


        map<int, int> ready;
        ready[0] = 0;

        it(i,0,n) ready[b[i]] += a[i];
        sort(all(b));
        int ans = 0; 
        h -= attackSum;
        ans++; 

        if (h > 0) {
            while (h > 0) {
                for (auto& p : ready) {
                    if (p.ff == 0) continue;
                    if (ans % p.ff == 0) h -= p.ss;
                    else if (p.ff > ans) break; 
                }    
            ans++;
            }
        }
        cout<<ans<<endl; 
    }
}