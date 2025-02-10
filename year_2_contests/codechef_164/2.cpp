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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, l, r; 
        cin>>n>>l>>r; 

        vi a(n);
        for (auto& i : a) cin>>i; 
        string ans; 
        bool dupl = false; 
        map<int, int> m;

        for (int i = 0; i < n; i++) m[a[i]]++;
        for (auto p: m) if (p.ss > 1) dupl = true; 

        int res = 1; 
        bool fd = false;

        for (int i = 0; i < n - 1; i++) {
            if (fd) break; 
            for (int j = i + 1; j < n; j++) {
                res *= (a[i] ^ a[j]);
                if (res > r) {
                    fd = true; 
                    break; 
                }
            }
        }
        if (l <= res && res <= r || (dupl && l == 0)) ans = "YES";
        else ans = "NO";

        cout<<ans<<endl; 
    }
}