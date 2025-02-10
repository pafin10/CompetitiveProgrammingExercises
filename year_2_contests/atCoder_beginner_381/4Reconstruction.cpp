#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
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
int g[2 * MAX_N];


int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t = 1;//cin>>t; 

    while(t--) {
        int n; cin>>n;
        vi a(n);
        vi last(n + 1);

        for (auto& i : a) cin>>i; 
        for (int i = 0; i < n; i++) last[i + 1] = -2;

        int ans = 0, l = 0; 
        g[0] = 0; 

        for (int i = 0; i < n; i++) {
            if ((i - l) % 2 == 0) {
                if (last[a[i]] == i - 1) l = last[a[i]];
                else if (last[a[i]] >= l) l = last[a[i]] + 1; 
            } 
            else if (a[i - 1] != a[i]) l = i; 
            ans = max(ans, i - l + 1);
            last[a[i]] = i;
        }
        cout<<2 * (ans / 2) <<endl; 

    }
}