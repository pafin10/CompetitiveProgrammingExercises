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
    // ifstream cin("xorPalindromes.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string s; cin>>s;

        string fi = s.substr(0, n / 2);
        string se = s.substr((n + 1) / 2, n /2);
        reverse(se.begin(), se.end());

        int mismatches = 0, matches = 0; 
        for (int i = 0; i < n/2; i++) (fi[i] == se[i]) ? matches++ : mismatches++;

        vector<int> ans(n + 1);
        int mid = 0;
        if (n % 2) mid = 1;

        for (int i = 0; i <= mid; i++) {
            for (int j = 0; j <= matches; j++) {
                ans[i + mismatches + 2 * j] = 1;
            }
        }
       
        for (auto& el: ans) cout<<el;
        cout<<endl; 

    }
}