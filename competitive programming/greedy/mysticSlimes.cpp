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
    // ifstream cin("mysticSlimes.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n);
        pair<int, int> maxi = {0, 0}; // val, pos

        for (int i = 0; i < n; i++) {
            cin>>a[i];
            if (a[i] >= maxi.first) {
                if (a[i] == maxi.first) {
                    if (i > 1 && i < n - 2) maxi = {a[i], i};
                }
                else maxi = {a[i], i};
            }
        }
        if (n == 2) {cout<<max(a[0], a[1]) - min(a[0], a[1])<<endl; continue;}

        int ans = 0;
        int maxi_left = 0;
        int maxi_right = 0;
        for (int i = 0; i < maxi.second; i++) {
            if (i == 1) maxi_left = max(maxi_left, a[i] - a[0]);
            else maxi_left = max(maxi_left, a[i]);
        }
        for (int i = maxi.second + 1; i < n; i++) {
            if (i == n - 2) maxi_right = max(maxi_right, a[i] - a[n-1]);
            else maxi_right = max(maxi_right, a[i]);
        }
        
        int tmp = maxi.first;
        if (maxi.second == 1) tmp -= a[0];
        if (maxi.second == n - 2) tmp -= a[n-1];

        ans = max(tmp, max(maxi_left, maxi_right));

        cout<<ans<<endl; 
            

    }
}