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
    //ifstream cin("mathematicalCircus.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        vector<pair<int, int>> ans;
        if (k == 0) {cout<<"NO"<<endl; continue;}
        else if (k % 2 == 0) {
            for (int i = 4; i <= n; i+=4) {
                ans.push_back({i-1, i});
            }
            for (int i = 2; i <= n; i+=4) {
                if ((i + k) % 4) {
                    ans.clear();
                    break; 
                }
                ans.push_back({i, i-1});
            }
        }
        else for (int i = 2; i <= n; i+=2) ans.push_back({i-1, i});
        if (ans.empty()) cout<<"NO"<<endl; 
        else {
            cout<<"YES"<<endl; 
            for (auto el: ans) cout<<el.first<<" "<<el.second<<endl; 
        }
    }
}