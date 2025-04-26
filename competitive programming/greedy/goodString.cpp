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
    // ifstream cin("goodString.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    string s; cin>>s; 

    string ans = "";
    for (int i = 0; i < n; i++) {
        int ind = ans.size();
        if (ind % 2) {
            if (s[i] != *(ans.end() - 1)) ans += s[i];
        }
        else {
            ans += s[i];
        }
    }
    if (ans.size() % 2) ans.erase(ans.end() - 1);
    cout<<(int) s.size() - (int)ans.size()<<endl; 
    cout<<ans<<endl; 
}