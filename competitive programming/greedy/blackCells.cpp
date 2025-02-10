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
const int INF = 1E9; 

int32_t main() {
    ifstream cin("blackCells.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);

        for (auto& i : a) cin>>i; 

        if (n == 1) {
            cout<<1<<endl; 
            continue; 
        }
        deque<int> d(a.begin(), a.end());
        pii max_dist = {0, 0}; // val, pos

        if (n % 2) {
            for (int i = 1; i < n; i++) {
                if (a[i] - a[i - 1] > max_dist.ff) {
                    max_dist = {a[i] - a[i - 1], i};
                }
            }
            // keep i and i - 1 separate
            int second_max = 0; 
            for (int i = max_dist.ss - 1; i >= 1; i -= 2) {
                second_max = max(second_max, a[i] - a[i - 1]);
            }
            for (int i = max_dist.ss + 1; i < n; i += 2) {
                second_max = max(second_max, a[i] - a[i - 1]);
            }
            if (second_max > max_dist.ff / 2) {
                d.insert(d.begin() + max_dist.ss, a[max_dist.ss - 1] + max_dist.ff / 2);
            }
            else {
                if (!(max_dist.ss % 2)) d.push_back(a[n - 1] + 1);
                else {
                    if (a[0]) d.push_front(a[0] - 1);
                    else {
                        int i;
                        for (i = 1; i < INF; i++) {
                            if (a[i] != i) break; 
                        }
                        d.insert(d.begin() + i, i);
                    }
                }
            }
        }
        vi dist; 
        for (int i = 1; i < d.size(); i+=2) {
            dist.pb(d.at(i) - d.at(i - 1));
        }
        sort(dist.rbegin(), dist.rend());
        cout<<dist[0]<<endl; 
    }
}