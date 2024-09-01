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
    ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        string s; 
        cin>>s; 
        s = "bb"+s+"bb"; n+=4;
        vi ind, pfa(n+1), pfc(n+1);
        int ans = INT32_MAX;
        it(i,0,n) {
            if (s[i] == 'b') ind.pb(i);
            pfa[i+1] = pfa[i] + (s[i] == 'a');
            pfc[i+1] = pfc[i] + (s[i] == 'c');
        }
        it(i,0,sz(ind)-1) {
            ans = min(ans, pfa[ind[i]] + pfc[n] - pfc[ind[i+1]]);
        }
        
        cout<<ans<<endl; 

    }
}