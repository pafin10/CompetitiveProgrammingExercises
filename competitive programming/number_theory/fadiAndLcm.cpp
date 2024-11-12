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


using namespace std;
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
    //ifstream cin("fadiAndLcm.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x; cin>>x;
    int a = 1, b = x; 
    if (x % 2 == 0 && lcm(2, x / 2) == x) a = 2, b = x / 2;

    for (int i = 3; i * i <= x; i++) {
        if (x % i == 0) {
            int j = x / i; 
            if (lcm(i, j) == x && max(i, j) < max(a, b)) {
                a = i; 
                b = j; 
            }
        }
    }
    cout<<a<<" "<<b<<endl; 
}