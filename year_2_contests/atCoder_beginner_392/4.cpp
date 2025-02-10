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
#include <iomanip>


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
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    vector<vector<int>> dice(n);

    vector<map<int, int>> dice_cnt(n);
    for (int i = 0; i < n; i++) {
        int k; cin>>k; 
        for (int j = 0; j < k; j++) {
            int tmp; cin>>tmp;
            dice[i].push_back(tmp);
            dice_cnt[i][tmp]++;
        }
    }

    long double max_prob = 0;
    for (int i = 0; i < n; i++) {
        vector<int> die = dice[i];
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            vector<int> paired_die = dice[j];

            vector<pair<int, int>> cnts;
            for (auto el : dice_cnt[i]) {
                if (dice_cnt[j].count(el.first)) {
                    cnts.push_back({el.second, dice_cnt[j][el.first]});
                }
            }
            long double total_prob = 0;
            int i_length = dice[i].size(), j_length = dice[j].size();
            for (auto cnt: cnts) {
                total_prob += ((long double)((long double)cnt.first / i_length) * 
                (long double)((long double)cnt.second / j_length));
            }
            max_prob = max(max_prob, total_prob);
        }
    }

    cout<<setprecision(10)<<max_prob<<endl; 
}