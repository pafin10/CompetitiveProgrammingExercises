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
//#define int long long
const int MAX_N = 100'005;

bool check(vector<int>& a, int k, int whole_or) {
    int or1 = 0;
    int n = a.size();
    if (n < k) return false; 
    vector<int> bit_cnt(31, 0);

    for (int i = 0; i < k; i++) {
        or1 |= a[i];
        
        for (int bit = 0; bit < 31; bit++) {
            if (a[i] & (1 << bit)) bit_cnt[bit]++;
        }
    }
    if (or1 != whole_or) return false; 

    for (int i = k; i < n; i++) {
        int leaving = a[i - k];
        int joining = a[i];

        for (int bit = 0; bit < 31; bit++) {
            if (leaving & (1 << bit)) bit_cnt[bit]--;
            if (joining & (1 << bit)) bit_cnt[bit]++;
            if (!bit_cnt[bit]) or1 &= ~(1 << bit);
        }
        if (or1 != whole_or) return false; 
    }
    return true;
}


int32_t main() {
    // ifstream cin("catFoxAndTheLonelyArray.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        vector<int> a(n);

        int whole_or = 0;
        for (auto& i: a) {
            cin>>i; 
            whole_or |= i;
        }
        if (n == 1) {cout<<1<<endl; continue;}

        int l = 0, r = n, k = 1;
        while (l < r && k) {
            k = (l + r) / 2; 
            if(check(a, k, whole_or)) {
                r = k;
            }
            else {
                l = k + 1;
            }
        }
        r = max(r, 1);
        cout << r << endl;
    }
}