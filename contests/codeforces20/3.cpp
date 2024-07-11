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
    ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        vector<pair<int, int>> v(n+m+1);
        it(i,0,n+m+1) cin>>v[i].ff;
        it(i,0,n+m+1) cin>>v[i].ss;
        vector<pair<int, int>> p, t; 
        int prog = 0, test = 0;


        it(i,0,n+m+1) {
            if (prog == n+1) {t.pb({v[i].ss, i}); continue;}
            else if (test == m+1) {p.pb({v[i].ff, i}); continue;}
            if (v[i].ff > v[i].ss && prog < n+1) {p.pb({v[i].ff, i}); prog++;}
            else {t.pb({v[i].ss, i}), test++;}
        }
        ll sum = 0;
        for (auto &x : p) sum += x.ff;
        for (auto &x : t) sum += x.ff;
        
        vll ans(n+m+1, sum);

        if (sz(p) == n+1) {
            // remove each programmer once
            it(i,0,sz(p)) {
                ans[p[i].ss] -= p[i].ff;
            }
            // remove each tester once. as we have one extra prog we're left with n+1 prog and 
            // m-1 testers. So we convert the last programmer to a tester
            ll pos = p.back().ss;
            it(i,0,sz(t)) {
                ans[t[i].ss] -= t[i].ff;
                ans[t[i].ss] -= v[pos].ff; 
                ans[t[i].ss] += v[pos].ss;
            }
        }
        // same for m+1 testers, n programmers
        else {
            it(i,0,t.size()) {
                ans[t[i].ss] -= t[i].ff;
            }
            ll pos = t.back().ss; 
            const ll det = v[pos].ff - v[pos].ss;
            for (auto &x : p) ans[x.ss] += det - x.ff; 
        }
        vout(ans);
        cout<<endl; 
    }
}