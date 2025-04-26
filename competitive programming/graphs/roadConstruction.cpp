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
    // ifstream cin("roadConstruction.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m; 
    vector<bool> center(n, true);

    for (int i = 0; i < m; i++) {
        int u, v; cin>>u>>v; 
        u--; v--; 
        center[u] = center[v] = false; 
    }

    int c = 0; 
    for (int i = 0; i < n; i++) {
        if (center[i]) {
            cout<<n - 1<<endl; 
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                cout<<(i + 1)<<" "<<(j + 1)<<endl;
            }
            break; 
        }
    }

}