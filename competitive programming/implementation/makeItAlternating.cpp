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
const int MOD = 998244353;

static int factorial(int x) {
    if (x == 0|| x == 1) return 1;
    int64_t result = 1;
    for (int i = 2; i <= x; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int32_t main() {
    // ifstream cin("makeItAlternating.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        string s; cin>>s; 
        int n = s.size();

        vector<int> lengths; 

        char cur = s[0];
        int length = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != cur) {
                lengths.push_back(length);
                length = 1;
            }
            else {
                length++;
            }
            cur = s[i];
        }
        lengths.push_back(length);

        int blocks = (int)lengths.size();
        int ops = n - blocks;
        unsigned int shortest_cnt = 1;

        for (int i = 0; i < blocks; i++) {
            shortest_cnt = (1LL * shortest_cnt * lengths[i]) % MOD; 
        }
        shortest_cnt *= factorial(ops);


        cout<<ops<<" "<<shortest_cnt % MOD<<endl; 
    }
}