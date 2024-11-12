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

string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    array<int, 2> ans = {0, 0};

    for (int i = 0; i < n; i++) dp[i][i] = true;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i+1] = true;
            ans = {i, i+1};
        }
    }

    for (int diff = 2; diff < n; diff++) 
        for (int i = 0; i < n - diff; i++) {
            int j = i + diff; 
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true; 
                if (j - i > ans[1] - ans[0]) {
                    ans = {i, j}; 
                }
            }
        }
    return s.substr(ans[0], ans[1] - ans[0] + 1);
}

int32_t main() {
    ifstream cin("longestPalindromicSubstring.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin>>s; 
    cout<<longestPalindrome(s)<<endl; 
    
}


