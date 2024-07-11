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

static vi findFactors(int x) {
    vi factors; 
    while (x>1) {
        int i = 2;
        while (x % i) i++;
        x /= i;
        factors.pb(i);
    }
    return factors;
}

int32_t main() {
    ifstream cin("missingNumbers.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        vi a(4); 
        it(i,0,4) cin>>a[i]; 
        sort(all(a));
        int n = sz(a);
        vi factors = findFactors(a[n-1]);
        //vout(factors);
        // second element is result of division
        // first is a+b or a-b
        // abs(a-b) gives difference

        // say a[0] is diff
        int part1 = 1, part2 = 1;
        vector<pair<int, int>> options; 
        it(i,0,sz(factors)) {
            part1 *= factors[i];
            it(j,i+1, sz(factors)) {
                part2 *= factors[j];
            }
            if (abs(part2-part1) == abs(a[0]) || abs(part2-part1) == abs(a[2]))
                options.pb({part1, part2});
            part2 = 1;
        }
        vector<pair<int, int>> optionsn; 
        for (auto& p: options) {
            if (p.ff / p.ss == a[1]) optionsn.pb({p.ff, p.ss});
            if(p.ss / p.ff == 1) optionsn.pb({p.ss, p.ff});
        };
        
        cout<<endl; 



    }
}