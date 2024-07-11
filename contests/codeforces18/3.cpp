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

int findMaxFinalValue(vi& a, int l, int r);
int findMedian(vi& a, int l, int r);


int findMedian(vi& a, int l, int r) {
    vi subarray(a.begin() + l, a.begin() + r + 1);
    sort(subarray.begin(), subarray.end());
    return subarray[(r - l) / 2];
}

int findMaxFinalValue(vi& a, int l, int r, int& maxMedian) {
    if (l == r) return a[l];


    int median = findMedian(a, l, r);
    maxMedian = max(maxMedian, median);

    int mid = (l + r) / 2;
    findMaxFinalValue(a, l, mid, maxMedian);
    findMaxFinalValue(a, mid + 1, r, maxMedian);

    return maxMedian;
}

int32_t main() {
    ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n);
        int maxInd = -1, maxi = -1;
        it(i,0,n) cin>>a[i];
        vi b(all(a));
        sort(all(b));
        int median = b[(n-1)/2];
        int ans = median;

        int finalVal = findMaxFinalValue(a, 0, n - 1, ans);

        cout << finalVal << endl;
    }
}