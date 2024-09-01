#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)
#define pb push_back

bool isBinaryDec(ll num) {
    bool binary = true; 
    if (num == 0) return false;
    while(num >= 1) {
        if ((num % 10) != 0 && (num % 10) != 1) {
            binary = false;
            break;
        }
        num /= 10;
    }
    return binary; 
}

set<ll> findFactors(ll n) {
    set<ll> factors;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    return factors;
}

bool canBeFullyBinaryDecomposed(ll num) {
    if (isBinaryDec(num)) return true; 

    set<ll> factors = findFactors(num);

    for (ll factor : factors) {
        return (canBeFullyBinaryDecomposed(factor));
    }
    return false; 
}

int main() {
    // ifstream cin("4.txt");
    int t;
    cin >> t;
    const int a = 10001;
    vector<int> binaryDec;
    it (i, a) {
        if (isBinaryDec(i)) binaryDec.pb(i);
    }
    while (t--) {
        ll n;
        cin >> n;
        bool ans = 0;
        int sz = binaryDec.size();
        it (i, sz) {
            if (n % (binaryDec[i]) == 0) {
                ans |= canBeFullyBinaryDecomposed(n/binaryDec[i]);
            }
        }
        ans ? cout<< "YES"<<endl : cout << "NO" <<endl; 
    }
    return 0;
}
