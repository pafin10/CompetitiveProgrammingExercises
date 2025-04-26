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
constexpr int MOD = 998244353;


int32_t main() {
    // CHECK SOLUTION!! 
    
    ifstream cin("6.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m, d; cin>>n>>m>>d; 
        vector<vector<bool>> wall(n, vector<bool>(m, false));
        vector<vector<bool>> usable(n, vector<bool>(m, false));


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x; cin>>x; 
                wall[i][j] = ((x == 'X') ? 1 : 0);
            }
        }

        int ans = 1; 
        set<int> last_holds;
        for (int i = n - 1; i >= 0; i--) {
            int start = 0, end = m; 
            if (i < n - 1) {

                // start and end must be calculated based on previous available holds
            }
            
            for (int j = start; j < end; j++) {
                int left = max(0, j - d);
                int right = min((int)wall[i].size(), j + d + 1); 

                int holds = accumulate(wall[i].begin() + left, wall[i].begin() + right, 0);
                
                if (holds) {
                    for (int m = start ; m < end; m++) if (wall[i][m]) last_holds.insert(m);
                    ans = (ans * holds) % MOD;
                    ans = (ans * holds * (holds - 1)) % MOD;
                }
                
            }

            
            
        }

        cout<<ans<<endl; 
    }
}