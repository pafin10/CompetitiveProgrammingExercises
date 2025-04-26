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
    // ifstream cin("liHuaAndMaze.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m;
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        int ans = 4;
        if ((x1 == 1 && y1 == 1) || (x2 == 1 && y2 == 1) || 
        (x1 == n && y1 == m) || (x2 == n && y2 == m) ||
        (x1 == 1 && y1 == m) || (x1 == n && y1 == 1) ||
        (x2 == 1 && y2 == m) || (x2 == n && y2 == 1)) ans = 2;
        else if (x1 == 1 || y1 == 1 || x2 == 1 || y2 == 1 ||
        x1 == n || y1 == m || x2 == n || y2 == m) ans = 3;

        cout<<ans<<endl; 
    }
}