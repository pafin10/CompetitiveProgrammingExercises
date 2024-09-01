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


using namespace std;
#define NDEBUG
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
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<vector<char>> a(2, vector<char>(n));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                cin>>a[j][i];
            }
        }
        if (n < 3) {cout<<0<<endl; continue;}

        int ans = 0;
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n - 2; i++) {
                if (a[j][i] == 'x' && a[j][i+1] == '.' && a[j][i+2] == 'x') {
                    if (j == 0) {
                        if (a[1][i] == '.' && a[1][i+1] == '.' && a[1][i+2] == '.') ans++; 
                    }
                    else {
                        if (a[0][i] == '.' && a[0][i+1] == '.' && a[0][i+2] == '.') ans++; 
                    }
                }
            }
        }
        cout<<ans<<endl; 
        
    }
}