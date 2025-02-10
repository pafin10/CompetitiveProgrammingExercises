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


int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    vector<int> a(n);

    for (auto& i : a) cin>>i; 

    vector<int> results, subsets;

    function<void(int)> backtrack = [&](int idx) -> void {
        if (idx == n) {
            int xor_sum = 0;
            for (auto& s : subsets) xor_sum ^= s;
            results.push_back(xor_sum);
            return;
        }
        for (int i = 0; i < (int)subsets.size(); i++) {
            int initial = subsets[i];
            subsets[i] += a[idx];
            backtrack(idx + 1);
            subsets[i] = initial;
        }
        subsets.push_back(a[idx]);
        backtrack(idx + 1);
        subsets.pop_back();
    };
    backtrack(0);
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());
    
    cout<<(int)results.size()<<endl; 

}