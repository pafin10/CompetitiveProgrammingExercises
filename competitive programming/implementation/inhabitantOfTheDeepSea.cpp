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
    // ifstream cin("inhabitantOfTheDeepSea.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        vi a(n);
        int sm = 0; 
        for (auto & i : a) {
            cin>>i; 
            sm += i; 
        }
        if (sm <= k) {cout<<n<<endl; continue;}

        
        int i = 0, j = n - 1;
        while (k > 0 && i <= j) {
            if (!(a[i] && a[j])) break; 
            int sub = min(a[i], a[j]);
            if (2 * sub <= k) {
                a[i] -= sub; 
                if (a[j]) a[j] -= sub; 
                k -= 2 * sub;
            }
            else {
                int prev_ai = a[i];
                a[i] -= min(a[i], (k + 1) / 2);
                k -= min(prev_ai, k);
                int prev_aj = a[j];
                a[j] -= min(a[j], k);
                k -= min(prev_aj, k);
            }
            if (!a[i]) i++;
            if (!a[j]) j--;
        }

        cout<<count(a.begin(), a.end(), 0)<<endl; 
    }
}