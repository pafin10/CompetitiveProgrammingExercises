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
    // ifstream cin("soldierAndBananas.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k, n, w; 
    cin>>k>>n>>w; 

    int pay = 0; 
    for (int i = 1; i <= w; i++) pay += i * k;
    cout<<(((n - pay) < 0) ? abs(n - pay) : 0 )<<endl; 
}