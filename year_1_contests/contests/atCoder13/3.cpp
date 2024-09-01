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


using namespace std;
#define NDEBUG
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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n; 
    vector<pii> p(n);
    int lb = 0, ub = 0; 
    vi dpR(n), dpL(n);

    for (int i = 0; i < n; i++) {
        cin>>p[i].ff;
        cin>>p[i].ss;
        lb += p[i].ff; 
        ub += p[i].ss;
        if (i) {
            dpL[i] = dpL[i-1] + p[i].ff;
            dpR[i] = dpR[i-1] + p[i].ss;
        }
        else {
            dpR[i] = p[i].ss;
            dpL[i] = p[i].ff;
        }
    }

    
    vi ans;
    if (lb > 0 || ub < 0) {
        cout<<"No"<<endl; 
    }
    else {
        cout<<"Yes"<<endl;
        int diff = ub;

        for (int i = 0; i < n; i++) {
            if (diff > 0) {
                if (p[i].ss - p[i].ff < diff) {
                    ans.pb(p[i].ff);
                    diff -= p[i].ss - p[i].ff; 
                }
                else {
                    ans.pb(p[i].ss - diff);
                    diff = 0;
                }
            }
            else if (diff == 0) ans.pb(p[i].ss);
            else cout<<"shouldn't happen";
        }
        for (auto & e: ans) cout<<e<<" ";
        cout<<endl; 
    }
}