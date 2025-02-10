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
#include <deque>


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

static vector<bool> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false; isPrime[1] = false; 
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; 
            }
        } 
    } 
    return isPrime;
}

int32_t main() {
    // ifstream cin("t-primes.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n; 
    vector<bool> isPrime = sieve(10e6);

    vector<int> b(n);
    for (auto& i : b) cin>>i; 

    for (auto i: b) {
        int p = sqrtl(i);
        if (isPrime[p] && p * p == i) cout<<"YES"<<" ";
        else cout<<"NO"<<" ";
        cout<<endl; 
    }
}