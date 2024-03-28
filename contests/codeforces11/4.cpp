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

bool isBinaryDec(ll num) {
    string str = to_string(num);
    for (char digit : str) {
        if (digit != '0' && digit != '1') {
            return false;
        }
    }
    return true;
}

set<ll> findFactors(ll n) {
    set<ll> factors;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                factors.insert(i);
                n /= i;
            }
        }
    }
    if (n > 1) factors.insert(n); 
    return factors;
}

bool canBeFullyBinaryDecomposed(ll num) {
    if (isBinaryDec(num)) return true; 

    set<ll> factors = findFactors(num);

    for (ll factor : factors) {
        if (isBinaryDec(factor) && isBinaryDec(num / factor)) {
            return true; 
        }
    }
    return false; 
}

int main() {
    //ifstream cin("4.txt");
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n==1) {cout<<"YES"<<endl; continue;}
        if (canBeFullyBinaryDecomposed(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
