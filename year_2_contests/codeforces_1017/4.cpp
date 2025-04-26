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
    int t; cin>>t; 

    while(t--) {
        string p, s; cin>>p>>s; 
        vector<pair<char, int>> subs, subs1;

        int last = 0;
        char cur = p[0];
        int n = (int)p.size(), m = (int)s.size();
        bool pos = true; 

        for (int i = 1; i < n; i++) {
            if (p[i] != cur) {
                subs.push_back({cur, i - last});
                last = i; 
                cur = p[i];
            }
        }
        if (subs.empty() || subs.back().first != cur) 
            subs.push_back({cur, n - last});

        last = 0, cur = s[0];
        for (int i = 1; i < m; i++) {
            if (s[i] != cur) {
                subs1.push_back({cur, i - last});
                last = i; 
                cur = s[i];
            }
        }

        if (subs1.empty() || subs1.back().first != cur) 
            subs1.push_back({cur, m - last});

        if (subs.size() != subs1.size()) pos = false; 
        else {
            int ind = 0;
            for (auto& sub: subs) {
                auto sub1 = subs1[ind];
                if (sub.first != sub1.first || sub1.second < sub.second || 2 * sub.second < sub1.second) {
                    pos = false; 
                    break;
                }
                ind++;
            }
        }

        if (pos) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl; 
    }
}