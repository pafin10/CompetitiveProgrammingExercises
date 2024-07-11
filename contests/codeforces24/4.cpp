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
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n,m; cin>>n>>m; 
        int maxi = 0, ind = 0;
        vector<vector<char>> lines; 
        it(i,0,n) {
            vector<char> k(m);
            int cnt = 0;
            it(j,0,m) {
                cin>>k[j];
                if (k[j] == '#') cnt++;
            } 
            lines.pb(k);
            if (cnt > maxi) {maxi = cnt; ind = i;}
        }
        int x = ind+1, y = 0;
        int start = 0;
        bool f = false; 
        it(i,0,m) {
            char curr = lines[ind][i];
            if (!f && curr == '#') {start = i; f = true;}
        }
        y = (start+1) + (maxi/2);
        cout<<x<<" "<<y<<endl; 
    }
}