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
    int t; cin>>t; 

    while(t--) {
        int n, m, k; cin>>n>>m>>k; 

        int max_benches = k / n;
        if (k % n) max_benches++;
        
        int free = m - max_benches, ans, blocks;

        if (m >= 2 * max_benches) ans = 1;
        else {
            blocks = min(m, free + 1);
            ans = max_benches / blocks + ((max_benches % blocks) ? 1 : 0);
        }
        cout<<ans<<endl; 


    }
}