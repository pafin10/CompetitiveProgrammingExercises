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


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("kevinAndGeometry.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n); 
        map<int, int> m; 

        for (auto & i: a) {
            cin>>i; 
            m[i]++;
        }

        sort(a.begin(), a.end());
        vector<int> ans;
        
        for (auto& p: m) {
            if (p.second >= 4) {
                for (int i = 0; i < 4; i++) ans.push_back(p.first);
                break; 
            }
        }

        int c = 0; 
        if (ans.empty()) {
            for (int i = n - 2; i >= 0; i--) {
                if (a[i] == a[i + 1]) {
                    c = 2 * a[i];
                    ans.push_back(a[i]); ans.push_back(a[i]);
                    a.erase(a.begin() + i, a.begin() + i + 2);
                    break; 
                }
            }
        }

        int min_diff = INT64_MAX;
        for (int i = 0 ; i < n - 3; i++) {
            min_diff = min(min_diff, a[i + 1] - a[i]);
            if (min_diff < c) {
                ans.push_back(a[i + 1]); ans.push_back(a[i]);
                break; 
            }
        }
        if (ans.size() < 4) cout<<-1; 
        else for (auto& i : ans) cout<<i<<" ";
        cout<<endl; 
    }
}