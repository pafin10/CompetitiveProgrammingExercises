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

int32_t main() {
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n,k; cin>>n>>k;
        vi a(n);
        it(i,0,n) cin>>a[i];
        int sumDiff = 0;
        it(i,0,n) {
            if (i) {
                sumDiff += abs(a[i] - a[i-1]);
            }
        }
        vi minVec(n), maxVec(n);
        int curr = abs(a[0] - a[1]);
        int tmp = abs(1 - a[1]);
        minVec[0] = tmp > curr ? tmp - curr : 0;

        it(i,1,n-1) {
            curr = abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]);
            tmp = abs(1 - a[i-1]) + abs(1 - a[i+1]);
            minVec[i] = tmp > curr ? tmp - curr : 0;
        }

        curr = abs(a[n-1] - a[n-2]);
        tmp = abs(1 - a[n-2]);
        minVec[n-1] = tmp > curr ? tmp - curr : 0;

        curr = abs(a[0] - a[1]);
        tmp = abs(k - a[1]);
        maxVec[0] = tmp > curr ? tmp - curr : 0;
        it(i,1,n-1) {
            int curr = abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]);
            int tmp = abs(k - a[i-1]) + abs(k - a[i+1]);
            maxVec[i] = tmp > curr ? tmp - curr : 0;   
        }
        curr = abs(a[n-1] - a[n-2]);
        tmp = abs(k - a[n-2]);
        maxVec[n-1] = tmp > curr ? tmp - curr : 0;

        int runSum = sumDiff;
        it(i,0,n) {
            sumDiff = max(sumDiff, runSum + max(maxVec[i], minVec[i]));
        }
        cout<<sumDiff<<endl; 
    }
}