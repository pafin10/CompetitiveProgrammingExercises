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
#include <stack>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
// #define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    primes.push_back(2);
    is_prime[2] = true; 

    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            if (p != 2) primes.push_back(p);
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}

vector<int> segmented_sieve(int low, int high, vector<int>& small_primes) {
    int size = high - low + 1;
    vector<bool> is_prime(size, true);

    for (int p : small_primes) {
        int start = max(p * p, ((low + p - 1) / p) * p);
        for (int i = start; i <= high; i += p) {
            is_prime[i - low] = false;
        }
    }

    vector<int> primes(small_primes);

    for (int i = 0; i < size; ++i) {
        if (is_prime[i] && (low + i) >= 2)
            primes.push_back(low + i);
    }

    return primes;
}

int32_t main() {
    // ifstream cin("5.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;

        vector<int> small_primes = sieve(n);
        int ans = 0; 

        if (!small_primes.empty()) {
            vector<int> primes = segmented_sieve(small_primes.back() + 1, n, small_primes);
            ans = (int)primes.size();
            for (int a = 2; a <= (n / 2); a++) {
                for (auto& p: primes) {
                    if (a * p <= n) ans++;
                    else break; 
                }
            }
        }

        cout<<ans<<endl; 
    }
}