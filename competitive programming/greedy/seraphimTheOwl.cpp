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
    //ifstream cin("seraphimTheOwl.txt");
    int t; cin>>t; 
    while(t--) {
        ll n,m; cin>>n>>m;
        vll a(n), b(n);
        it(i,0,n) cin>>a[i];
        it(i,0,n) cin>>b[i];
        reverse(all(a));
        reverse(all(b));
        
        ll pref = 0, bSum = 0;
        it (i,0,(n-m)) {
            if (a[i] < b[i]) {
                pref += bSum;
                pref += a[i];
                bSum = 0;
            }
            else bSum += b[i];
        }
        ll ans = 1e18;
        it (i, n-m, n) {
            ans = min(ans, pref+bSum+a[i]);
            bSum += b[i];
        }
        cout<<ans<<endl; 
    }
}