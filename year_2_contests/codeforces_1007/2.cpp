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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        int sum = accumulate(a.begin(), a.end(), 0LL);
        
        int s = sqrtl(sum);
        if (s * s == sum) {
            cout<<-1<<endl; 
            continue;
        }

        reverse(a.begin(), a.end());
        int cum_sum = 0;
        for (int i = 0; i < n - 1; i++) {
            cum_sum += a[i];
            int tmp = sqrtl(cum_sum);
            if (cum_sum == tmp * tmp) {
                cum_sum -= a[i];
                cum_sum += a[i + 1];
                swap(a[i], a[i + 1]);
            }
        }

        for (auto i: a) cout<<i<<" ";
        cout<<endl; 
    }
}