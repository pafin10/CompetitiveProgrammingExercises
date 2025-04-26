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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin>>q; 

    while(q--) {
        int n; cin>>n; 
        string s, t; cin>>s>>t; 

        if (s == t) {cout<<0<<endl; continue;}
        if (s[0] != t[0]) {cout<<-1<<endl; continue;}
        

        bool one = s[0] == '1'; 
        bool pos = true; 
        
        
        vector<int> ops; 

        for (int i = 1; i < n; i++) {
            if (!one && (s[i] != t[i])) pos = false; 

            if (one && s[i] == '0') {
                s[i] = '1';
                ops.push_back(i);
            }
            if (s[i] == '1') one = true; 
            else one = false; 
        }

        if (!pos) {cout<<-1<<endl; continue;}
        if (s == t) {
            cout<<(int)ops.size()<<endl;
            for (auto op: ops) cout<<op<<" "; 
            continue;
        }

        for (int i = n - 1; i >= 1; i--) {
            if (t[i] == '0') {
                if (s[i] == '1') ops.push_back(i);
                s[i] = '0';
            }
        }

        cout<<(int)ops.size()<<endl; 
        for (auto op: ops) cout<<op<<" "; 
        cout<<endl;

    }
}