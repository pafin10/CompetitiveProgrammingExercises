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
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n; 
    vector<char> ans; 

    if (n % 2) {
        for (int i = 0; i < n; i++) {
            if (i * 2 + 1 == n) ans.push_back('=');
            else ans.push_back('-');
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i * 2 == n || (i + 1) * 2 == n) ans.push_back('=');
            else ans.push_back('-');
        }
    }
    cout<<string(ans.begin(), ans.end())<<endl; 

}