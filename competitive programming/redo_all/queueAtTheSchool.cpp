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
    // ifstream cin("queueAtTheSchool.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t; cin>>n>>t; 
    string s; cin>>s;

    vector<char> ans(s.begin(), s.end());
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (ans[j] == 'B' && ans[j + 1] == 'G') {
                swap(ans[j], ans[j + 1]);
                j++;
            }
        }
    }
    cout<<string(ans.begin(), ans.end())<<endl; 
    
}