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
#include <array>


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
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;

static int binaryExpRecursive(int x, int n, int M);
static int binaryExpIterative(int x, int n, int M);

void apply(vi& S, vi& P) {
    vi tmp(S.size());
    int n = S.size();

    for (int i = 1; i < n; i++) {
        tmp[i] = S[P[i]];
    }
    for (int i = 1; i < n; i++) {
        S[i] = tmp[i];
    }
}

void binaryPermutation(vi& S, vi& P, int K) {
    while (K) {
        if (K & 1) 
            apply(S, P);
        apply(P, P);
        K >>= 1;
    }
}

int main(int argc, char const *argv[]) {
    cout<<binaryExpRecursive(2, 6, 10)<<endl;
    cout<<binaryExpIterative(2, 6, 10)<<endl;

    vector<int> P{ 0, 2, 3, 4, 1 };
    vector<int> S{ 0, 2, 1, 3, 4 };
    int K = 2;
    binaryPermutation(S, P, K);
    cout << "New Sequence = ";
    for (int i = 1; i < S.size(); i++)
        cout << S[i] << " ";
    return 0;
    return 0;
}

static int binaryExpRecursive(int x, int n, int M) {
    x = x % M;
    if (n == 0) return 1;
    else if (n % 2 == 1) return (x * binaryExpRecursive(x, n-1, M)) % M;
    else return (binaryExpRecursive(x * x, n / 2, M)) % M;
}

static int binaryExpIterative(int x, int n, int M) {
    int ans = 1; 
    while (n > 0) {
        if (n & 1) ans = (ans * x) % M;
        x = (x * x) % M;
        n >>= 1;
    }
    return ans; 
}







