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


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; 
    cin>>n>>k; 
    if (k > n) {
        cout<<1<<endl; 
    }
    else {
        vector<int> a(n + 1);

        int sum = k; 
        for (int i = 0; i < k; i++) a[i] = 1;

        a[k] = sum; 
        sum = (sum + a[k]) % INF;

        for (int i = k + 1; i <= n; i++) {
            sum = (sum - a[i - k - 1] + INF) % INF;
            a[i] = sum; 
            sum = (sum + a[i]) % INF;
        }
        cout<< (a[n] % INF) <<endl; 
    } 

    
}