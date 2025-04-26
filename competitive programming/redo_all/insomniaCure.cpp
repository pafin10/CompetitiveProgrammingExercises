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
    // ifstream cin("insomniaCure.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, l, m, n, d; 
    cin>>k>>l>>m>>n>>d; 

    int ans = 0;
    for (int i = 1; i <= d; i++) {
        if (i % k == 0) ans++;
        else if (i % l == 0) ans++;
        else if (i % m == 0) ans++;
        else if (i % n == 0) ans++;
    }
    cout<<ans<<endl; 
}