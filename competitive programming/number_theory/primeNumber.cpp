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
#include <deque>


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
const int MOD = 1e9 + 7;

static int pow(int a, int b) {
    if (b == 0) return 1 % MOD; 
    if (b % 2 == 0) {
        int p = pow(a, b / 2); 
        return 1LL * p % MOD * p % MOD; 
    }
    else {
        int p = pow(a, (b - 1) / 2);
        return 1LL * p * p % MOD * a % MOD;
    }
}

int32_t main() {
    // ifstream cin("primeNumber.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin>>n>>x; 
    vector<int> a(n);

    int s = 0; 
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        s += a[i];
    }

    map<int, int> cnt; 
    for (int i = 0; i < n; i++) {
        cnt[s - a[i]]++;
    }
    int cur = s - a[n - 1];
    while (cnt[cur] % x == 0) {
        cnt[cur + 1] += cnt[cur] / x; 
        cnt[cur] = 0; 
        cur++;
    }
    cur = min(cur, s); // Why this
    int num = pow(x, cur); 
    cout<<num<<endl; 
}