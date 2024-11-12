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

int32_t main() {
    //ifstream cin("arrowPath.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<vector<char>> grid(2, vector<char>(n));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin>>grid[i][j];
            }
        }
        if ((grid[0][1] == '<' && grid[1][0] == '<') || grid[1][n-2] == '<') {
            cout<<"NO"<<endl; 
            continue;
        }

        int ans = 1, j = 0;
        while (j < n - 1) {
            if (grid[0][j+1] == '<' && grid[1][j] == '<') {
                ans = 0; 
                break; 
            }
            if (j < n - 2 && (grid[0][j+1] == '<' && grid[1][j+2] == '<')) {
                ans = 0; 
                break; 
            }
            else j += 2;
        }
        cout << (ans ? "YES" : "NO") << endl;

    }
}