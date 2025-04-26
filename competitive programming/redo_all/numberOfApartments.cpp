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
    // ifstream cin("numberOfApartments.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        array<int, 3> ans;
        bool fd = false; 
        for (int i = 0; i <= n / 3; i++) {
            for (int j = 0; j <= n / 5; j++) {
                for (int k = 0; k <= n / 7; k++) {
                    if (3 * i + 5 * j + 7 * k == n) {
                        ans = {i, j, k};
                        fd = true; 
                        break; 
                    }
                }
            }
        }
        if (fd) cout<<ans.at(0)<<" "<<ans.at(1)<<" "<<ans.at(2)<<endl; 
        else cout<<-1<<endl; 
    }
}