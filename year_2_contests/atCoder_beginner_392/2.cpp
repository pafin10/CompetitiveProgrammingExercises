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
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin>>n>>m; 
    vector<int> a(m);

    for (auto& i: a) cin>>i; 

    sort(a.begin(), a.end());
    vector<int> ans(n); 
    iota(ans.begin(), ans.end(), 1);

    set<int> se(ans.begin(), ans.end());

    for (auto& i: a) se.erase(i);

    if (se.empty()) cout<<0<<endl; 
    else {
        cout<<se.size()<<endl; 
        for (auto& i: se) cout<<i<<" ";
        cout<<endl; 
    }
    
}