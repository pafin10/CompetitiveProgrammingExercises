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
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    // ifstream cin("penchickAndBBQBuns.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        vi ans;
        bool pos = true; 
        if (!(n % 2)) {
            for (int i = 1; i <= n / 2; i++) {
                ans.pb(i);
                ans.pb(i);
            }
        }
        else {
            if (n < 27) pos = false; 
            else {
                ans.resize(n, 0);
                ans[0] = 1; ans[9] = 1; ans[25] = 1;
                ans[10] = 2; ans[26] = 2;
                int cnt = 3; 
                bool inc = false; 
                for (int i = 0; i < n; i++) {
                    if (!ans[i]) {
                        if (i && ans[i - 1] == cnt) {
                            if (!inc) {
                                ans[i] = cnt; 
                                inc = true; 
                            }
                            else {
                                ans[i] = ++cnt; 
                                inc = false; 
                            }
                        }
                        else {
                            ans[i] = ++cnt; 
                            if (ans[i - 1] == 2) inc = false;
                        }
                    }
                }
            }
        }
        if (pos) {
            for (auto& i : ans) cout<<i<<" ";
            cout<<endl; 
        } 
        else cout<<-1<<endl; 
    }
}