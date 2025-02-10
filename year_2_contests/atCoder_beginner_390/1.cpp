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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> p;
    for (int i = 1; i <= 5; i++) {
        int j; cin>>j; 
        if (i != j) p.push_back(j);
    }
    string ans = "Yes";
    if ((int)p.size() != 2 || p[1] != p[0] - 1) ans = "No";
    
    cout<<ans<<endl; 
}