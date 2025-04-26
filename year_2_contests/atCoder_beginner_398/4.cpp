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
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, r, c; cin>>n>>r>>c; 
    string s; cin>>s; 

    string ans = "";
    set<pair<int, int>> smoke; 

    pair<int, int> cur = {0, 0};
    smoke.insert(cur);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            r++;
            cur.first++;
        }
        else if (s[i] == 'W') {
            c++;
            cur.second++;
        }
        else if (s[i] == 'S') {
            r--;
            cur.first--;
        }
        else {
            c--;
            cur.second--;
        }
        smoke.insert(cur);
        
        auto it = smoke.find({r, c});
        if (it != smoke.end()) ans += '1';
        else ans += '0';
    }
    cout<<ans<<endl; 
}