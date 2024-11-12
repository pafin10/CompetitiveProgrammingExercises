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
    //ifstream cin("divisiblePairs.txt");
    int t; cin>>t; 
    while(t--) {
        ll n,x,y; cin>>n>>x>>y;
        vll a(n);
        ll ans = 0;
        map<pair<ll, ll>, ll> cnt;
        it(i,0,n) cin>>a[i];
        it(i,0,n) {
            ll modX = a[i]%x, modY = a[i]%y;
            ans += cnt[make_pair((x-modX)%x, modY)];
            cnt[make_pair(modX, modY)]++;
        }
        cout<<ans<<endl; 
    }
}