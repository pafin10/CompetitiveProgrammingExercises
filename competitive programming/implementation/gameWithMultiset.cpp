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
#include <unordered_set>
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
int cnt[30];

int32_t main() {
    // ifstream cin("gameWithMultiset.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin>>m; 
    
    while(m--) {
        int t, v; cin>>t>>v;
        if (t == 1) {
            cnt[v]++;
        }
        else {
            string ans = "NO";
            int sum = 0; 
            bool pos = false; 
            for (int i = 0; i < 30; i++) {
                int rem = (v % (1 << (i + 1))) / (1 << i);
                if (rem > sum + cnt[i]) {
                    break;
                }
                v -= rem * (1 << i); 
                sum = (sum + cnt[i] - rem) / 2;
            }
            if (!v) pos = true; 

            cout << (pos ? "YES" : "NO") << endl;        
        }    
    }
}