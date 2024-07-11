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
#include <unordered_set>


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
const int MAX_SQRT = 100000;
const int MAX_N = 10E4;

vector<bool> sieve(int n);
vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}


int32_t main() {
    //ifstream cin("5.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    vector<bool> is_prime = sieve(MAX_SQRT);
    vi primes;
    unordered_set<int> prime_squares;

    for (int i = 2; i <= MAX_SQRT; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            prime_squares.insert(i * i);
        }
    }

    while(t--) {
        int n; cin>>n; 
        bool found = false; 
        int a = 2, a2 = 4; 

         for (size_t i = 0; i < sz(primes) && !found; ++i) {
            int b2 = primes[i] * primes[i];
            int c2 = n - a2 - b2;

            if (c2 > 0 && prime_squares.find(c2) != prime_squares.end()) {
                int c = sqrt(c2);
                if ((c * c) == c2 && is_prime[c] && c != primes[i]) {
                    found = true; 
                    break;
                }
            }
        }
        
        if (found) cout<<"Yes"<<endl; 
        else cout<<"No"<<endl; 

    }
}