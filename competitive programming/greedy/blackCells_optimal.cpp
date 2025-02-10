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
const int INF = 1E9; 

int32_t main() {
    // ifstream cin("blackCells.txt");
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

        int k = INT64_MAX;
        if (n % 2 == 1) {  
            for (int i = 0; i < n; i++) {
                for (int m = 0; m < 2; m++) {
                    deque<int> d(a.begin(), a.end());

                    if (m == 0 && i < d.size()) 
                        d.insert(d.begin() + i + 1, d.at(i) + 1);
                    else if (m == 1 && i + 1 < d.size()) 
                        d.insert(d.begin() + i + 1, d.at(i + 1) - 1);

                    int tmp_k = 0;
                    for (int j = 1; j < d.size(); j+= 2) {
                        tmp_k = max(tmp_k, d.at(j) - d.at(j - 1));
                    }
                    k = min(k, tmp_k);
                }
            }
        } else {  
            k = 0;
            for (int i = 1; i < n; i += 2) {
                k = max(k, a[i] - a[i - 1]);
            }
        }
        cout<<k<<endl; 
    }
}