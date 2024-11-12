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


using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
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

vector<vector<char>> getSpiralOrder(vector<vector<char>>& M, int n, int m) {
    vector<vector<char>> spiral(min(n, m) / 2); 
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int layer = 0; // outermost

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) spiral[layer].pb(M[top][j]);
        top++;

        for (int i = top; i <= bottom; i++) spiral[layer].pb(M[i][right]);
        right--;

        for (int j = right; j >= left; j--) spiral[layer].pb(M[bottom][j]);
        bottom--;

        for (int i = bottom; i >= top; i--) spiral[layer].pb(M[i][left]);
        left++;

        layer++;
    }

    return spiral; 
}

int32_t main() {
    // ifstream cin("iLove1543.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        int ans = 0; 
        vector<vector<char>> M(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>M[i][j];
            }
        }
        
        vector<vector<char>> spiral = getSpiralOrder(M, n, m);
        int len = 4; 
        
        for (vector<char> layer : spiral) {
            string s(layer.begin(), layer.end());
            s += s.substr(0, len - 1);
            for (int i = 0; i < s.size() - len + 1; i++) {
                if (s.substr(i, len) == "1543") ans++;
            }
        }
        cout<<ans<<endl; 
        
    }
}