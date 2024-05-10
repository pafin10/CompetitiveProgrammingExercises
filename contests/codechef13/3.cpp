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
#define rev(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define INF (ll)1e18

int main(int argc, char const *argv[]) {
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    ll maxi = (ll)1e9;
    while(t--) {
        ll n; cin>>n;
        ll cnt = 0;
        vll a(n+1); a[0] = 0;
        it(i,1,n+1) cin>>a[i];
        it(i, 1, n+1) {
            if (a[i] == 1) {cnt += n; continue;}
            int pos = ceil(log(maxi) / log(a[i]));
            it(j,1,min(pos, sz(a))) {
                if (pow(a[i], j) <= a[j]) cnt++;
            }
        }
        cout<<cnt<<endl; 
    }
}