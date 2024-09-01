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
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        int x = 0;

        for (int i = 0; i < n; i++) {
            int l; cin>>l; 
            vi cnt(l+2);

            int mex = 0;
            for (int j = 0; j < l; j++) {
                int a; cin>>a;
                if (a <= l+1) {
                    cnt[a]++;
                }
            }
            while (cnt[mex] > 0) mex++;
            mex++;
            while (cnt[mex] > 0) mex++;
            x = max(x, mex);
        }
        int ans;
        if (x <= m) {
            ans = x * x + (x + m) * (m - x + 1) / 2;
        }
        else {
            ans = (m + 1) * x;
        }
        cout<<ans<<endl; 
    }
}