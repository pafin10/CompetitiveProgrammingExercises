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
#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("5.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n), sums(n), bits(31);
        

        for (auto& i: a) cin>>i; 

        for (int bit = 30; bit >= 0; bit--) {
            for (int i = 0; i < n; i++) {
                bits[bit] += ((a[i] & (1 << bit)) ? 1: 0);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int bit = 30; bit >= 0; bit--) {
                bool is_set = ((a[i] & (1 << bit)) ? 1: 0);
                if (is_set) {
                    int not_set = n - bits[bit];
                    tmp += (not_set * (1 << bit));
                }
                else {
                    tmp += (bits[bit] * (1 << bit));
                }
            }
            ans = max(ans, tmp);
        }
        cout<<ans<<endl; 
    }
}