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
#include <array>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
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
const int INF = 1E9;


int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, d, k; cin>>n>>d>>k;
        vi pre(n - d + 2, 0);

        for (int i = 0; i < k; i++) {
            int l, r; cin>>l>>r; 
            l--;
            l = max(0, l - d + 1);
            r = min(r, n - d + 1);
            pre[l]++;
            pre[r]--;
        }
        for (int i = 1; i <= n - d + 1; i++) {
            pre[i] += pre[i-1];
        }
        cout<<max_element(pre.begin(), pre.end() - 1) - pre.begin() + 1<< " " 
        <<min_element(pre.begin(), pre.end() - 1) - pre.begin() + 1<<endl;
    }
}