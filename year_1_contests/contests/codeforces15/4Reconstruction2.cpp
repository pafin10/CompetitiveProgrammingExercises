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
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        ll n,k,b,s; cin>>n>>k>>b>>s; 
        vll a(n+1), p(n+1);
        it(i,1,n+1) cin>>p[i];
        it(i,1,n+1) cin>>a[i];

        auto f = [&](ll i) {
            ll score = 0, runScore = 0;
            for (ll j = 0; j < k && j < n; i = p[i], j++) {
                score = max(runScore + a[i] * (k-j), score);
                runScore += a[i];
            }
            return score; 
        };
        ll bod = f(b), sash = f(s);
        if (bod > sash) cout<<"Bodya"<<endl; 
        else if (bod < sash) cout<<"Sasha"<<endl; 
        else cout<<"Draw"<<endl;
    }
}