#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
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
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        vector<vi> mat(n, vi(m, 2));

        for (int i = 0, j = 0; i < n; i++, j++) {
            if (j == m) j = 0;
            mat[i][j] = 3;
        }
        for (int i = 0, j = 0; j < m; i++, j++) {
            if (i == n) i = 0;
            mat[i][j] = 3;
        }
        for (auto& row : mat) {
            for (auto& i : row) cout<<i<<" ";
            cout<<endl; 
        }
    }
}