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

int find_j(int i, int n) {
    int l = 1, r = i - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int diff = static_cast<int>(i) * i * i - static_cast<int>(mid) * mid * mid;
        if (diff == n) return mid; 
        else if (diff < n) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return 0;
}



int32_t main() {
    // ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    int a = -1, b = -1; 

    double cube_root = cbrtl(n);
    int k = static_cast<int>(cube_root);
    
    if (k * k * k == n || k * k * k < n) k++;
    
    int l = k - 1;
    bool found = false; 
    for (int i = k; (i * i * i) - (l * l * l) <= n; i++) {
        if (found) break; 
        int j = find_j(i, n);

        if ((i * i * i ) - (j * j * j) == n) {
            a = i; b = j;
            found = true;
            break;
        }
        k++; l++;
    }
    if (a != -1 && b != -1) cout<<a<<" "<<b<<endl; 
    else cout<<-1<<endl; 
}