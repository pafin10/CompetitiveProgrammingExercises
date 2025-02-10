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
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<int> a(n), b(n);
        
        map<int, int> ma, mb; 
        for (auto& i: a) {
            cin>>i; 
            ma[i]++;
        }

        for (auto& i : b) {
            cin>>i; 
            mb[i]++;
        }

        string ans = "NO";
        set<int> se;
        if (ma.size() >= 3 || mb.size() >= 3) ans = "YES";
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    se.insert(a[i] + b[j]);
                }
            }
        }
        if (se.size() >= 3) ans = "YES";
        cout<<ans<<endl; 
    }
}