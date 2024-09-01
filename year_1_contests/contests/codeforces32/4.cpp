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
    ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m;
        vector<pii> mexs(n); // second element for #consecutive elements after mex

        for (int i = 0; i < n; i++) {
            int l; cin>>l; 
            set<int> seq;
            int mex = 0;
            for (int j = 0; j < l; j++) {
                int el; cin>>el; 
                seq.insert(el);
            }
          
            while (seq.find(mex) != seq.end()) {
                mex++;
            }

            int consecutive_count = 0;
            int current = mex + 1;

            while (seq.find(current) != seq.end()) {
                consecutive_count++;
                current++;
            }
            
            mexs[i].ff = mex; 
            mexs[i].ss = consecutive_count;
        }

        sort(mexs.begin(), mexs.end());
        int ans = 0; 

        auto f = [] (int x, vector<pii> mexs) -> int {
            int i = 0, out = 0; 
            int n = sz(mexs);
            while (i < n && (mexs[i].ff + mexs[i].ss >= mexs[i+1].ff) || x > out) {
                out = max(x, mexs[i+1].ff);
                i++;
            }
            int curr = 0, prev = -1; 
            int j = 0;
            while (j < n && curr > prev) {
                curr = mexs[j].ff;
                if (x == mexs[j].ff + 1) curr = x; 
                j++;
                out = max(out, curr);
            }
            if (i < n && out != x) {
                out = max(x, mexs[i].ff + mexs[i].ss);
            }
            return out; 
        };

        for (int i = 0; i <= m; i++) {
            ans += f(i, mexs);
        }
        cout<<ans<<endl; 
    }
}