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
    // ifstream cin("seaBattle.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b, k; 
    cin>>n>>a>>b>>k; 

    string s; cin>>s; 
    vector<int> ans;
    int cnt = 0; 
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt++;
        else cnt = 0; 
        if (cnt == b) ans.push_back(i + 1), cnt = 0;
    }

    cout<<(int)ans.size() - a + 1<<endl; 
    for (int i = 0; i < ans.size() - a + 1; i++) cout<<ans[i]<<" ";
    cout<<endl; 
    
}