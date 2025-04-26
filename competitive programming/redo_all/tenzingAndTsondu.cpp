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
    // ifstream cin("tenzingAndTsondu.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        
        int ts = 0, te = 0;
        for (int i = 0; i < n; i++) {
            int j; cin>>j; 
            ts += j;
        }
        for (int i = 0; i < m; i++) {
            int j; cin>>j; 
            te += j;
        }
        if (ts > te) cout<<"Tsondu"<<endl; 
        else if (ts < te) cout<<"Tenzing"<<endl; 
        else cout<<"Draw"<<endl; 
    }
}