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
    // ifstream cin("divideAndConquer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n);

        for (auto& i: a) cin>>i;
        int sum = accumulate(a.begin(), a.end(), 0);

        int ans = INT32_MAX;
        if (sum % 2) {
            for (int i = 0; i < n; i++) {
                int rest = a[i] % 2, cnt = 0;
                while (a[i] % 2 == rest) {
                    a[i] /= 2;
                    cnt++;
                }
                ans = min(ans, cnt);
            }
        }
        else ans = 0;
        cout<<ans<<endl; 
    }
}