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
int sum_until[3 * MAX_N];

int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    deque<int> q;
    int sum_left = 0;
    int left_cnt = 0;

    while(t--) {
        int f; cin>>f;
        int l, k;
        if (f == 1) cin>>l;
        else if (f == 3) cin>>k; 

        if (f == 1) {
            q.emplace_back(l);
            if (q.size() == 0) {
                sum_until[1] = l;
            } else {
                sum_until[q.size() + left_cnt] = sum_until[q.size() - 1 + left_cnt] + l;
            }
        }
        else if (f == 2) {
            sum_left += q[0];
            q.pop_front();
            left_cnt++;
        }
        else {
            cout<<sum_until[(k - 1) + left_cnt] - sum_left<<endl; 
        }
            
    }
}