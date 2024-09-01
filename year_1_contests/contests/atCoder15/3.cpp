#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
#define int long long
const int MAX_N = 100'005;

int32_t main() {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin>>n>>m;
    vi a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    if (sum <= m) {
        cout<<"infinite"<<endl; 
    }
    else {
        int val = m / n;
        sort(a.begin(), a.end());
        auto canDistribute = [&](int val) {
            int currentSum = 0;
            for (int i = 0; i < n; i++) {
                currentSum += min(a[i], val);
                if (currentSum > m) {
                    return false;
                }
            }
            return currentSum <= m;
        };

        int left = 0, right = m, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout<<result<<endl; 

    }
}