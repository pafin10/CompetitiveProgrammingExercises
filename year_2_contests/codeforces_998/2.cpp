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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m; 
        vector<vector<int>> cow_cards(n, vector<int>(m));

        vector<int> p;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)  {
                cin>>cow_cards[i][j];
            }
            sort(cow_cards[i].begin(), cow_cards[i].end());
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[cow_cards[i][0]] = i;
        }

        for (auto pair: mp) {
            p.push_back(pair.second);
        }
        int ans = 1;
        for (int i = m; i < n * m; i++) {
            int cow = p[(i - 1) % n];
            bool found = false; 
            for (int j = 0; j < m; j++) {
                if (cow_cards[cow][j] == i - 1) {
                    found = true;
                    break; 
                }
            }
            if (!found) {
                ans = -1;
                break; 
            }
        }

        if (ans == -1) cout<<ans<<endl; 
        else {
            for (auto& i: p) cout<<i + 1<<" ";
            cout<<endl; 
        }





    }
}