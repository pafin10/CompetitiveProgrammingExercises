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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n; 
    vi h(n);
    map<int, set<int>> m;

    for (int i = 0; i < n; i++) {
        cin>>h[i]; 
        m[h[i]].insert(i);
    }
    
    map<int, int> ans; // el, ans
    for (auto& pair : m) {
        set<int> se = pair.ss; 
        int max_range = *se.rbegin() - *se.begin();
        int ans_el = 1; 
        
        for (int start_pos : se) { // each starting pos
            int cnt = 1;
            max_range = (*se.rbegin() - start_pos);
            for (int j = 1; j <= max_range; j++) { // each pos interval
                int jump = j; 
                cnt = 1;
                int next_pos = start_pos + jump;

                while (se.count(next_pos)) {
                    cnt++;
                    next_pos += jump; 
                }
                ans_el = max(ans_el, cnt);
            }
        }
        ans[pair.ff] = ans_el; 
    }
    auto out = max_element(ans.begin(), ans.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second < b.second;
            });
    cout<<out -> second <<endl; 
}