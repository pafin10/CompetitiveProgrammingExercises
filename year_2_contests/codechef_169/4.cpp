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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;

static bool check(int mid, vector<int>& a, int k, int n) {
    int group_sum = 0, groups = 1; 
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (group_sum + a[i] <= mid) group_sum += a[i];
            else {
                group_sum = a[i];
                groups++;
            }
        }
        if (groups > k + 1) return false;
    }
    if (group_sum > mid) return false; 
    return true; 
}

// CHECK SOLUTION - UPSOLVE
int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n);

        int max_el = 0, sum = 0;
        int k = 0;
        for (auto& i: a) {
            cin>>i;
            if (i < 0) k++;
            sum += i; 
            max_el = max(max_el, i);
        }
        
        if (max_el <= 0) {
            cout<<0<<endl; 
            continue;
        }
        int l = max_el, r = sum;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid, a, k, n)) {
                r = mid;
            }
            else l = mid + 1;
        }
        cout<<l<<endl; 

    }
}