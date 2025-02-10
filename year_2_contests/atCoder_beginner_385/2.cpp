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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h, w, x, y; 
    cin>>h>>w>>x>>y; 

    vector<vector<char>> g(h + 1, vector<char> (w + 1));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin>>g[i][j];
        }
    }
    string t; cin>>t; 
    pii pos = {x, y};
    set<pii> houses; 
    for (int i = 0; i < (int)t.size(); i++) {
        if (t[i] == 'U') {
            char next = g[pos.ff - 1][pos.ss];
            if (next != '#') {
                pos.ff -= 1;
                if (next == '@') houses.insert(pos);
            }
        } 
        else if (t[i] == 'D') {
            char next = g[pos.ff + 1][pos.ss];
            if (next != '#') {
                pos.ff += 1;
                if (next == '@') houses.insert(pos);
            }
        }
        else if (t[i] == 'L') {
            char next = g[pos.ff][pos.ss - 1];
            if (next != '#') {
                pos.ss -= 1;
                if (next == '@') houses.insert(pos);
            }
        }
        else {
            char next = g[pos.ff][pos.ss + 1];
            if (next != '#') {
                pos.ss += 1;
                if (next == '@') houses.insert(pos);
            }
        }
    }

    cout<<pos.ff <<" "<<pos.ss <<" "<<sz(houses)<<endl; 
    
}