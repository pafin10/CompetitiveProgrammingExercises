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

int32_t main() {
    //ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;//cin>>t; 

    while(t--) {
        int n, k; cin>>n>>k; 
        vi a(n);
        ll overallSum = 0;
        it(i,0,n) {cin>>a[i]; overallSum += a[i];}
        //vi sums(n+1);

        // case 1: overall sum negative and k negative
        if (k <= 0) {
            if (overallSum < k) {cout<<"No"<<endl; continue;}
            else {
                sort(a.rbegin(), a.rend());
                //sums[0] = 0;
                //it(i,1,n+1) sums[i] = sums[i-1] + a[i-1];
            }
        }
        else {
            sort(all(a));
            //sums[0] = 0;
            //it(i,1,n+1) sums[i] = sums[i-1] + a[i-1];
        }
        cout<<"Yes"<<endl; 
        vout(a);
        cout<<endl; 
    }
}