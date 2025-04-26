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
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    vector<int> a(n);

    map<int, int> front, back; 
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        front[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        front[a[i]]--;
        back[a[i]]++;
        auto it = front.find(a[i]);
        if ((it -> second) == 0) {
            front.erase(it);
        }
        ans = max(ans, (int)front.size() + (int)back.size());
    }
    cout<<ans<<endl; 
}