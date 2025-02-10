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
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m;
        string s; cin>>s; 

        vector<vector<int>> mat(n, vector<int>(m));
        vector<int> row_sums(n), col_sums(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int el; cin>>el; 
                mat[i][j] = el;
            }
        }

        for (int i = 0; i < n; i++) {
            int row_sum = 0;
            for (int j = 0; j < m; j++) {
                row_sum += mat[i][j];
                col_sums[j] += mat[i][j];
            }
            row_sums[i] = row_sum;
        }
        
        pair<int, int> pos = {n - 1, m - 1};

        int len = n + m - 2;
        int i = 0;

        while (pos.first >= 0 && pos.second >= 0) {
            int el_fill;
            if (s[len - i - 1] == 'D') {
                el_fill = -row_sums[pos.first];
                mat[pos.first][pos.second] = el_fill;
                col_sums[pos.second] += el_fill;
                pos.first--;
            }
            else {
                el_fill = -col_sums[pos.second];
                mat[pos.first][pos.second] = el_fill;
                row_sums[pos.first] += el_fill;
                pos.second--;
            }
            i++;
        }

        for (auto& r: mat) {
            for (auto& el: r) {
                cout<<el<<" ";
            }
            cout<<endl; 
        }
    }
}