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
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("yetAnotherPermutationProblem.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<bool> used(n + 1, false);
        vector<int> ans; 
        int cur = 1;

        while (ans.size() < n) {
            int init_cur = cur;
            while (cur <= n) {
                used[cur] = true;
                ans.push_back(cur);
                cur *= 2;
            }
            cur = init_cur + 1;
            while (used[cur]) cur++;
        }
        for (auto& p: ans) cout<<p<<" ";
        cout<<endl; 
    }
}