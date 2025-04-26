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
#include <tuple> 


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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string A, B; 
        cin>>A>>B;

        string B_tmp = B; 
        reverse(B_tmp.begin(), B_tmp.end());
        vector<int> dp(n); // length of match ending at dp[i]
        vector<int> mismatch_dp(n);

        if (B_tmp[0] == A[0]) dp[0] = 1;
        else dp[0] = 0;
        if (B[0] != A[0]) mismatch_dp[0] = 1;
        else mismatch_dp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (B_tmp[i] == A[i]) dp[i] = dp[i - 1] + 1;
            else dp[i] = 0;
            if (A[i] != B[i]) mismatch_dp[i] = mismatch_dp[i - 1] + 1;
            else mismatch_dp[i] = 0;
        }

        vector<tuple<int, int, int>> ans; 

        for (int i = 0; i < n - 1; i++) {
            int tmp = max(mismatch_dp[i], dp[i]);
            if (mismatch_dp[i + 1] > tmp || dp[i + 1] > tmp) continue; 
            // above breaks it bc dp[i] is also nonzero for exactly equal sequences
            else {
                if (!mismatch_dp[i]) continue;
                if (mismatch_dp[i] == tmp) ans.push_back({1, i + 1 - mismatch_dp[i] + 1, i + 1});
                else ans.push_back({2, i + 1 - dp[i], i});
            }
        }
        if (mismatch_dp[n - 1] && (ans.empty() || get<2>(ans.back()) != n)) {
            ans.push_back({1, n - mismatch_dp[n - 1] + 1, n});
        }

        cout<<(int)ans.size()<<endl; 
        for (auto& k: ans) {
            int a, b, c; 
            tie(a, b, c) = k; 
            cout<<a<<" "<<b<<" "<<c<<" "<<endl; 
        }
    }
}