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
#define sz(x) (int)x.size()
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> p(2 * n + 1, -1), used(2 * n + 1, false);


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int k; cin>>k; 
                p[i + j] = k;
                used[k] = true;
            }
        }

        for (int i = 1; i <= 2 * n; i++) {
            if (!used[i]) {
                p[1] = i;
                break; 
            }
        }
        for (int i = 1; i <= 2 * n; i++) cout<<p[i]<<" ";
        cout<<endl; 
    }
}