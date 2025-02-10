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

int power(int k, int i) {
    int ans = 1; 
    while (i > 0) {
        if (i & 1) ans = (ans * k);
        k = (k * k);
        i >>= 1;
    }
    return ans; 
}

int32_t main() {
    // ifstream cin("insaneProblem.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int k, l1, r1, l2, r2;
        cin>>k>>l1>>r1>>l2>>r2;

        int ans = 0; 
        int k_n = 1;
        for (int i = 0; r2 / k_n >= l1; i++) {

            ans += max(0ll, min(r2 / k_n, r1) - max((l2 - 1) / k_n + 1, l1) + 1ll); 

            k_n *= k;
        }
        

        cout<<ans<<endl;         
    }
}