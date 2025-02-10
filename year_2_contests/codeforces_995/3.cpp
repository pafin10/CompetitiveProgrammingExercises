#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
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
#include <deque>


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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m, k; cin>>n>>m>>k; 
        vector<int> a(m), q(k);

        for (auto& i: a) cin>>i; 
        for (auto& i: q) cin>>i; 

        vector<char> ans(m);
        bool all = false; 
        if (n == k) all = true; 

        if ((n - 1) != k) {
            for (int i = 0; i < m; i++) {
                if (all) ans[i] = '1';
                else ans[i] = '0';
            }
        } 
        else {
            int cant = 0; 
            for (int i = 0; i < k; i++) {
                if (i + 1 != q[i]) {
                    cant = i + 1;
                    break; 
                }
            }
            if (!cant && q[k - 1] == k) cant = n; 
            for (int i = 0; i < m; i++) {
                if (a[i] == cant) ans[i] = '1';
                else ans[i] = '0';
            }
        }

        string out(ans.begin(), ans.end());
        cout<<out<<endl; 
    }
}