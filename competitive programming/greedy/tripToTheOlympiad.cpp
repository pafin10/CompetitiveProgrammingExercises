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
    // ifstream cin("tripToTheOlympiad.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int l, r; cin>>l>>r; 
        unsigned int A, B, C;

        int k = 31 - __builtin_clz(l ^ r);
        int a = l | ((1 << k) - 1), b = a + 1, c = (a == l ? r : l);
        cout << a << " " << b << " " << c << "\n";
        
    }
}