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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        if ((k == 1 && n == 1) || (k == 2 && n%2)) {
            cout<<-1<<endl; 
            continue; 
        }
        set<int> s;
        for (int i = 1; i <= n; i++) s.insert(i);

        vi p; 
        p.pb(-1);
        int ans = 0;
        for (int i = 1; i <= n - (n % k); i++) {
            int m = i % k;
            bool f = false;
            for (auto j: s) {
                if (m < k - 1) {
                    if (j % k == m + 1) {
                        p.pb(j);
                        s.erase(j);
                        f = true; 
                        break;
                    }
                }
                else {
                    if (!(j % k)) {
                        p.pb(j);
                        s.erase(j);
                        f = true; 
                        break; 
                    }
                }
            }
            if (!f) ans = -1;
        }

        for (int i = n - (n % k) + 1; i <= n; i++) {
            p.pb(i);
            for (int j = 1; j <= n - (n % k); j++) {
                if ((p[j] % k) != (i % k) && ((i % k) != (j % k))) {
                    swap(p[i], p[j]);
                    break; 
                }
            }
        }

        for (int i = 1; i <= n; i++) if ((p[i] % k) == (i % k)) ans = -1;
        if (ans != -1) {
            for (auto e : p) if (e != -1) cout<<e<<" ";
            cout<<endl;
        }
        else cout<<ans<<endl;
        
    }
}