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
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, s_x, s_y; 
    cin>>n>>m>>s_x>>s_y; 

    map<int, vector<int>> x_coord, y_coord; 
    vector<pair<char, int>> seq(n);

    for (int i = 1; i <= n; i++) {
        int x, y; 
        cin>>x>>y; 
        x_coord[x].push_back(y);
        y_coord[y].push_back(x);
    }
    for (auto& s : seq) cin>>s.ff>>s.ss; 
    for (auto p: x_coord) sort(p.ss.begin(), p.ss.end());
    for (auto p: y_coord) sort(p.ss.begin(), p.ss.end());

    pii pos = {s_x, s_y};
    set<pii> houses; 

    for (int i = 0; i < (int)seq.size(); i++) {
        if (seq[i].ff == 'U') {
            pos.ss += seq[i].ss;
            // check for given x coord how many houses fall in range, 
            // similar for others
        } 
        else if (seq[i].ff == 'D') {
            int placeholder = 0; 
            
        }
        else if (seq[i].ff == 'L') {
            int placeholder = 0; 
            
        }
        else {
            int placeholder = 0; 
        }
    }

    cout<<pos.ff <<" "<<pos.ss <<" "<<sz(houses)<<endl; 
    
}