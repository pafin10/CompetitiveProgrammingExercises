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
#include <stack>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("6.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m, k; 
        cin>>n>>m>>k; 
        vector<int> p(k);

        vector<int> cur(m, -1), last(m, -1); 
        bool shift = false; 

        for (int i = 0; i < n; i++) {
            cur.clear();
            for (int j = 0; j < m; j++) {
                int el = ((i * m + j) % k) + 1;
                if (el == last[j]) shift = true; 
                cur.push_back(el);
            }
            if (shift) {
                rotate(cur.begin(), cur.begin() + 1, cur.end());
                shift = false; 
            }
            last = cur; 
            
            for (auto el : cur) cout<<el<<" ";
            cout<<endl; 
        }
        
    }
    
}