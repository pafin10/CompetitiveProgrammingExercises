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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    vector<int> a(n);
    map<int, int> m; 

    for (int i = 0; i < n; i++) {
        cin>>a[i]; 
        m[a[i]]++;
    }

    int ans = -1, maxi = -1;
    for (int i = 0; i < n; i++) {
        if (m[a[i]] == 1) {
            if (a[i] > maxi) {
                maxi = a[i];
                ans = i + 1;
            }
        }
    }
    cout<<ans<<endl; 

}