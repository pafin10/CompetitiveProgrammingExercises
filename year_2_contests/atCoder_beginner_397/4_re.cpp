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
#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  

int solve(int a, int b, int c) {
    // ay^2 + by + c == 0
    int l = 0, r = 600000001;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (mid * mid * a + mid * b + c > 0) {
            r = mid;
        }
        else {
            if (mid * mid * a + mid * b + c < 0) {
                l = mid;
            }
            else return mid;
        }
    }
    return -1;
}

int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    // (x^3 - y^3) == n

    // d <= cube_root(n)
    int x = - 1, y = -1; 
    for (int d = 1; d <= 1000000; d++) {
        if (n % d != 0) continue;

        int m = n / d; // = 3*y^2 + 3*dy + d^2
        y = solve(3, 3 * d, d * d - m);

        if (y > 0) {
            x = d + y;
            break;
        }
    }
    if (x > 0 && y > 0) cout<<x<<" "<<y<<endl; 
    else cout<<-1<<endl; 
}