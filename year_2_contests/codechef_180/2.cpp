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
#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  
constexpr int MOD = 998244353;

int modExp(int base, int exp, int MOD) {
    int result = 1;
    base %= MOD;  

    while(exp > 0) {
        if(exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;  
    }
    return result;
}

int32_t main() {
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        
        if (n % 2 == 1) {
            cout<<modExp(2, n - 1, MOD) % MOD<<endl; 
        }
        else {
            int a = modExp(2, n - 2, MOD);
            int b = modExp(2, n - 1, MOD);
            cout<<(a + b) % MOD<<endl; 
        }
    }   
}