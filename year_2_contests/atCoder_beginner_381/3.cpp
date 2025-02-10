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
    int t; t=1; //cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s;
        cin>>s; 

        int ans = 1;
        vi pos; 

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '/' && s[i - 1] != '/' && s[i + 1] != '/') 
                pos.pb(i);
        }

        for (auto start : pos) {
            int l = start, r = start; 
            for (int i = start - 1; i >= 0; i--) {
                if (s[i] != '1') {
                    l = i + 1; 
                    break;
                }
                if (!i && s[i] == '1') l = 0;
            }
            for (int i = start + 1; i < n; i++) {
                if (s[i] != '2') {
                    r = i - 1; 
                    break; 
                }
                if (i == n - 1 && s[n - 1] == '2') r = n - 1;
            }
            ans = max(ans, 2 * min(start - l, r - start) + 1);
        }
        cout<<ans<<endl; 
    }
}