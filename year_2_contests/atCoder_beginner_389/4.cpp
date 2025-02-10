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


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;

// CHECK SOLUTION
int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R; cin>>R;

    auto in = [&] (int a, int b) {
        return (2 * a + 1) * (2 * a + 1) + (2 * b + 1) * (2 * b + 1) <= 4 * R * R;
        // just * 4 to avoid double imprecision 
    };
    int cnt = 0;
    int up = R - 1;
    int ans = 4 * (R - 1) + 1;

    for (int i = 1; in(i, 1); i++) {
        while (!in(i, up)) up--;
        cnt += up;
    }
    ans += cnt * 4;
    cout<<ans<<endl; 

}