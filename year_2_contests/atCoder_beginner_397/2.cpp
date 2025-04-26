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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin>>s; 
    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((ans + i) % 2 == 0) {
            if (s[i] != 'i') ans++;
        }
        else {
            if (s[i] != 'o') ans++;
        }
    }
    if ((n + ans) % 2 == 1) ans++;
    cout<<ans<<endl; 
}