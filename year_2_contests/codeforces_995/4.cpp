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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;

// TOO SLOW, APPARENTLY SHOULD HAVE SORTED THE ARRAY 
int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, x, y; 
        cin>>n>>x>>y; 

        vector<int> a(n);
        int sum = 0, maxi = 0; 
        for (auto& i : a) {
            cin>>i;
            sum += i; 
            if (i > maxi) maxi = i; 
        }

        if (sum < x || (sum - 2 * maxi > y)) {
            cout<<0<<endl;
            continue;
        }

        vector<int> max_remove(n), min_remove(n);
        for (int i = 0; i < n; i++) {
            max_remove[i] = max(0LL, (sum - a[i]) - x);
            min_remove[i] = max(0LL, (sum - a[i]) - y);
        }

        multiset<int> ms;
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            int curr_max = max_remove[i];
            int curr_min = min_remove[i];

            if (curr_max) {
                auto count_below_max = ms.lower_bound(curr_max + 1);
                auto count_below_min = ms.lower_bound(curr_min);     

                ans += distance(ms.begin(), count_below_max) - distance(ms.begin(), count_below_min);

                ms.insert(a[i]);
            }
        }

        cout<<ans<<endl; 
    }
}