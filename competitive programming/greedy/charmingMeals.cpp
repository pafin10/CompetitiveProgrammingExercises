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
    // ifstream cin("charmingMeals.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n), b(n);

        for (auto& i: a) cin>>i; 
        for (auto& i: b) cin>>i; 

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    
        int ans = 0;
        int min_diff = INT32_MAX;

        for (int j = 0; j < n; j++) {
            min_diff = INT32_MAX;
            for (int i = 0; i < n; i++) {
                min_diff = min(min_diff, abs(a[i] - b[(i + j) % n]));
            }
            ans = max(ans, min_diff);
        }
        
        
        cout<<ans<<endl; 
        
    }
}