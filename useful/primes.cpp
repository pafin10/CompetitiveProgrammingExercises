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
//#define int long long
const int MAX_N = 100'005;

bool isPrime(int x) {
    if (x == 2) return true; 
    if (x % 2 == 0 || x == 1) return false; 

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false; 
    }
    return true;
}

vi getFactorization(int x) {
    vi ans; 
    int i = 2; 
    while (x != 1) {
        while (x % i == 0) {
            ans.pb(i);
            x /= i; 
        }
        i++;
        if (i % 2 == 0) i++;
    }
    return ans;
}