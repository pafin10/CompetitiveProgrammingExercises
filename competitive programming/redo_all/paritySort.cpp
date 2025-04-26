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
    // ifstream cin("paritySort.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n);

        vector<bool> even(n, false);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            if (a[i] % 2 == 0) even[i] = true;
        }
        sort(a.begin(), a.end());
        
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0 && !even[i]) ans = "NO";
            if (a[i] % 2 && even[i]) ans = "NO";
        }
        cout<<ans<<endl; 
    }
}