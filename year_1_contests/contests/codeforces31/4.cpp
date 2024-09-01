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
const int INF = 1E9;
const string color = "BGRY";

int id(int x, int y) {
    if (x > y) swap(x,y);
    return y * (y - 1) / 2 + x;
}

int32_t main() {
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, q; cin>>n>>q; 
        vector<array<int, 2>> cities(n); 

        for (int i = 0; i < n; i++) {
            string s; cin>>s; 
            for (int j = 0; j < 2; j++) {
                cities[i][j] = color.find(s[j]);
            }
        }
        
        vector<array<int, 6>> pre(n), nxt(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) pre[i].fill(-1);
            else pre[i] = pre[i-1];

            pre[i][id(cities[i][0], cities[i][1])] = i;
        }

        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) nxt[i].fill(-1);
            else nxt[i] = nxt[i+1];

            nxt[i][id(cities[i][0], cities[i][1])] = i;
        }

        while (q--) {
            int x, y; cin>>x>>y; 
            x--; y--; 
            if (y < x) swap(x, y);

            bool f = false; 
            int ans = INF;

            for (auto a : cities[x]) {
                if (f) break; 
                for (auto b : cities[y]) {
                    if (a == b) {
                        cout<<abs(y - x)<<endl; 
                        f = true; 
                        break;
                    }

                    int w = id(a, b);
                    for (auto j : {pre[y][w], nxt[x][w]}) {
                        if (j >= 0 && j < n)
                            ans = min(ans, abs(j - y) + abs(j - x));
                    }
                }
            }
            if (!f) cout<<( (ans == INF) ? -1 : ans )<<endl; 
        }  
    }
}