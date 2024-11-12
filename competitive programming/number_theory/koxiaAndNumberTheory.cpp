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

bool isPrime(int x) {
    if (x == 2) return true; 
    if (x % 2 == 0 || x == 1) return false; 

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false; 
    }
    return true;
}
int32_t main() {
    //ifstream cin("koxiaAndNumberTheory.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        set<int> elements;

        bool distinct = 1;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            if (elements.count(a[i])) distinct = 0;
            elements.insert(a[i]);
        }
        if (!distinct) {
            cout<<"NO"<<endl; 
            continue;
        }

        int ans = 1;
        // for all relevant primes, we check whether there is a residue class
        // mod p which only one element of a belongs to. If so, x can be chosen 
        // in such a way as to make all a[i] + x coprime.  
        for (int p = 2; p <= n / 2; p++) {
            if (isPrime(p)) {
                vi ms(p, 0);
                for (int j = 0; j < n; j++) {
                    ms[a[j] % p]++;
                }
                if (*min_element(ms.begin(), ms.end()) >= 2) {
                    ans = 0; 
                    break;
                }
            }
        }
    
        cout<< (ans ? "YES" : "NO") <<endl; 
    }
}