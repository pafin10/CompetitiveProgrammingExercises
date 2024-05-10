#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int main(int argc, char const *argv[]) {
    //ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        ll n,k,b,s; cin>>n>>k>>b>>s;
        vll a(n+1), p(n+1);
        it(i,1,n+1) cin>>p[i];
        it(i,1,n+1) cin>>a[i];

        auto f = [&] (ll i) {
            ll ans = 0, sum = 0;
            for (ll j = 0; j < k && j < n; j++, i=p[i]) {
                ans = max(ans, sum + (k-j)*a[i]);
                sum += a[i];
            }
            return ans; 
        };

        ll fb = f(b), fs = f(s);
        if (fb > fs) cout<<"Bodya"<<endl; 
        else if (fb < fs) cout<<"Sasha"<<endl; 
        else cout<<"Draw"<<endl; 
    }
}