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
    // TOO SLOW: WORST CASE IS STILL O(N^2) EVEN THOUGH IT WAS UNINTUITIVE AT FIRST
    // INSTEAD: INVERT PROBLEM; CHECK ALL CANDIDATE GCDS AND TAKE MAX
    
    // ifstream cin("gcdAddSize.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        vector<int> a(n);

        map<int, int> freq;
        int total_gcd;
        for (auto& i:a) {
            cin>>i;
            freq[i]++;
        }
        total_gcd = a[0];
        sort(a.rbegin(), a.rend());
        set<int> visited;

        int ans = 0;
        int tmp = a[0] + freq[a[0]];
        // maybe need to sort freq by keys, was the initial plan

        int pointer = 0;
        while (pointer < n && visited.size() < n) {

            int cur_el = a[pointer];
            visited.insert(cur_el);
            tmp = cur_el + freq[cur_el];
            int length = freq[cur_el], curr_gcd = cur_el;

            for (auto rit = freq.rbegin(); rit != freq.rend(); rit++) {
                auto pair = *rit;
                total_gcd = gcd(total_gcd, pair.first);

                if (cur_el % pair.first == 0 && cur_el != pair.first && !visited.count(pair.first)) {
                    visited.insert(pair.first);
                    curr_gcd = gcd(curr_gcd, pair.first);

                    if (curr_gcd == gcd(cur_el, pair.first)) {
                        if (gcd(cur_el, pair.first) + length + pair.second > tmp) {
                            tmp = gcd(cur_el, pair.first) + length + pair.second;
                            length += pair.second;
                        }
                    }
                    else {
                        if (gcd(cur_el, pair.first) + freq[tmp] + pair.second > tmp) {
                            tmp = gcd(cur_el, pair.first) + freq[tmp] + pair.second;
                            length = pair.second + freq[tmp];
                        }
                    }   
                }
            }
            ans = max(ans, tmp);
            tmp = 0;
            while (a[pointer] == cur_el) pointer++;
        }

        cout<<max(ans, n + total_gcd)<<endl; 
        
    }
}