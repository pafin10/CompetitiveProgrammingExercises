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
#include <climits>


using namespace std;
#define NDEBUG
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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        it(i,0,n) cin>>a[i];

        unordered_map<int, int> freq;
        it(i, 0, n) freq[a[i]]++;

        int minCost = LLONG_MAX;
        for (auto &entry : freq) {
            int element = entry.ff;
            int count = entry.ss;
            int cost = (n - count) * element;
            minCost = min(minCost, cost);
        }
        it(i,1,n+1) {
            if (freq.find(i) == freq.end()) {
                minCost = min(minCost, n * i);
            }
        }

        cout << minCost << endl;
    }
}