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
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  


int32_t main() {
    // ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        string s; 
        cin>>s; 

        int tmp = k;
        string s1 = s;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && s[i] == '0' && s[i + 1] == '1' && k > 0) {
                k--;
                s[i] = '1';
            }
        }

        k = tmp;
        for (int i = n - 1; i >= 0; i--) {
            if (i > 0 && s1[i] == '1' && s1[i - 1] == '0' && k > 0) {
                k--;
                s1[i - 1] = '1';
            }
        }
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ans1++;
            if (s1[i] == '1') ans2++;
        }
        cout<<max(ans1, ans2)<<endl; 
    }
}