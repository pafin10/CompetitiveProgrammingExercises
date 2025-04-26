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
#include <stack>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m; 
    vector<vector<int>> meals(m + 1); 
    vector<vector<bool>> like(m + 1, vector<bool>(n + 1, true));
    vector<int> sz(m + 1, 0);

    for (int i = 1; i <= m; i++) {
        int k; cin>>k; 
        sz[i] = k;
        for (int j = 1; j <= k; j++) {
            int l; cin>>l;
            meals[i].push_back(l);
            like[i][l] = false; 
        }
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin>>b[i];
    
    vector<int> ans(n + 1, 0), cnts(m + 1, 0);
    vector<bool> used(m + 1, false);

    for (int d = 1; d <= n; d++) {
        if (d > 1) ans[d] = ans[d - 1];
        int del = b[d];

        for (int i = 1; i <= m; i++) {
            if (!like[i][del]) cnts[i]++;
            like[i][del] = true;
        }

        for (int i = 1; i <= m; i++) {
            if (!used[i] && cnts[i] == (int)sz[i]) {
                ans[d]++;
                used[i] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout<<ans[i]<<endl;

}