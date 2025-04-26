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
    // ifstream cin("misloveHasLostAnArray.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l, r; cin>>n>>l>>r; 
    map<int, int> mini, maxi;
    mini[1] = n - (l - 1);
    maxi[(1 << (r - 1))] = n - (r - 1);
    int cnt = 2;
  
    for (int i = 0; i < n - mini[1]; i++) {
        mini[cnt] = 1;
        cnt *= 2;
    }
    cnt = 1;
    for (int i = 0; i < n - maxi[(1 << (r - 1))]; i++) {
        maxi[cnt] = 1;
        cnt *= 2;
    }
    int ans_mini = 0, ans_maxi = 0;
    for (auto el: mini) ans_mini += el.first * el.second;
    for (auto el: maxi) ans_maxi += el.first * el.second;

    cout<<ans_mini<<" "<<ans_maxi<<endl; 
}
        
    
