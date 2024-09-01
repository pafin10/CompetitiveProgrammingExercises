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
#define int long long
const int MAX_N = 100'005;

static int power(int base, int exponent) {
    int i = 1; 
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            i *= base; 
        }
        base *= base;
        exponent /= 2;
    }
    return i; 
}
int32_t main() {
    ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n; 
    int digits = floor(log10(n)) + 1;
    vi a(21);
    a[0] = 0;
    a[1] = 10;

    for (int i = 2; i <= 19; i++) {
        a[i] = a[i-1] + 9 * power(10, i - 2);
    }
    // so, until 100 there are a[2] palindrome numbers, 
    // i.e. palindrome numbers with two digits or less
    int i = 0;
    while (n >= a[i]) i++;
    int ans = 0;


    // from here on, ans is a[digits] + ratio of palindrome numbers left to numbers in next range, 
    // scaled by the average difference between palindromes (around 10). then some further adjustment
    // approach was right i think but didn't fully get the last part / not enough time. check sol
    int diff = n - a[digits];
    ans = power(10, digits) + double(double(diff) / (a[i+1] - a[i])) * a[i+1] * 10;
    cout<<ans<<endl; 



}