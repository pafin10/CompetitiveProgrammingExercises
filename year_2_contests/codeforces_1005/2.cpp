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
#include <deque>
#include <functional>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n), pref_dist(n + 1), suf_dist(n + 1);

        for (auto& i: a) cin>>i;
        if (n == 1) {
            cout<<1<<" "<<1<<endl; 
            continue;
        }

        int lout = -1, rout = -1;
        set<int> se;

        for (int i = 0; i < n; i++) {
            se.insert(a[i]);
            pref_dist[i + 1] = se.size();
        }
        se.clear();
        
        for (int i = n - 1; i >= 0; i--) {
            se.insert(a[i]);
            suf_dist[i] = se.size();
        }
        int full_score = n - pref_dist[n - 1];
        int l = 0, r = n - 1;

        while (r > l && pref_dist[r + 1] - pref_dist[l] != 0) {
            r--; l++;
        }

        if (r < n - 1 && pref_dist[r + 1] - pref_dist[l] == 0) {rout = r + 1; lout = l;}
        else if (l && pref_dist[r] - pref_dist[l - 1] == 0) {rout = r; lout = l - 1;}
        else if (l > 0 && r < n - 1) {lout = l - 1; rout = r - 1;}

        if (lout != -1 && rout != -1) cout<<lout<<" "<<rout<<endl; 
        else cout<<0<<endl; 
    }
}