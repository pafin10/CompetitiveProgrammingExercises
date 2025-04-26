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
    // I WAS TRYING TO SOLVE A HARDER PROBLEM THAN NECESSARY!
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string a, b; 
        cin>>a>>b; 
        if (a == b) {cout<<0<<endl; continue;}

        vector<tuple<int, int, int>> ans; 
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                int j = i; 
                while (j < n && a[j] != b[j]) j++;
                ans.push_back({1, i + 1, j});
                for (int k = i; k < j; k++) {
                    a[k] = (a[k] == '1') ? '0' : '1';
                }
            }
        }

        cout<<(int)ans.size()<<endl; 
        for (auto& m: ans) {
            int tp, st, en; 
            tie(tp, st, en) = m;
            cout<<tp<<" "<<st<<" "<<en<<endl; 
        }
    }
}