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
#include <stack>


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
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin>>n>>k; 
    string s; cin>>s; 
    if (n == 1) cout<<s<<endl; 
    else {
        string t = s;
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'o') k--;
            else if (s[i] == '?') left++;
        }

        // first run
        for (int i = 0; i < n; i++) {
            if (i == 0 && t[i] == '?') {
                if (t[1] == 'o') {
                    t[0] = '.';
                    left--;
                }
            }
            else if (i == n - 1 && t[i] == '?') {
                if (t[i - 1] == 'o') {
                    t[i] = '.';
                    left--;
                }
            }
            else {
                if (t[i] == '?' && (t[i - 1] == 'o' || t[i + 1] == 'o')) {
                    t[i] = '.'; 
                    left--;
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(2, -1)); // num 'o's left to fill
        int start = 0; 
        for (int i = 0; i < n; i++) if (t[i] == '?') {start = i; break;}
        dp[start][0] = k;
        dp[start][1] = k - 1;

        for (int i = start + 1; i < n; i++) {
            if (t[i] != '?') {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
                continue;
            }

            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] - 1;
        }

        if (dp[n - 1][0] == 0 && dp[n - 1][1] > 0) {
            t[start] = '.';
            char cur = 'o';
            for (int i = start + 1; i < n; i++) {
                if (t[i] == '?') {
                    t[i] = cur; 
                    if (cur == 'o') cur = '.';
                    else cur = 'o';
                }
            }
        }
        else if (dp[n - 1][1] == 0 && dp[n - 1][0] > 0) {
            t[start] = 'o';
            char cur = '.';
            for (int i = start + 1; i < n; i++) {
                if (t[i] == '?') {
                    t[i] = cur; 
                    if (cur == 'o') cur = '.';
                    else cur = 'o';
                }
            }
        }
        cout<<t<<endl; 
    }

    

    
}