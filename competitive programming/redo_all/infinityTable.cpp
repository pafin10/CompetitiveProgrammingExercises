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
    // ifstream cin("infinityTable.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int k; cin>>k; 
        int fs = sqrt(double(k));
        if (fs * fs == k) {
            if (k == 1) cout<<fs<<" "<<fs<<endl;
            else cout<<fs<<" "<<1<<endl; 
            continue;
        }

        pair<int, int> ans = {1, fs + 1};
        int cnt = fs * fs + 1;

        while (cnt != k) {
            if (cnt < fs * fs + 1 + fs) 
                ans.first++;
            else 
                ans.second--;
            cnt++;
        }
        cout<<ans.first<<" "<<ans.second<<endl; 
    }
}