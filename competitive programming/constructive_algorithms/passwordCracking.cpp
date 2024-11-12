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

int ask(string s) {
    cout<<"? "<<s<<endl; 
    cout.flush();
    int res; cin>>res;
    return res; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        string curr;

        while ((int) curr.size() < n) {
            if (ask(curr + '0')) {
                curr += '0';
            }
            else if (ask(curr + '1')) {
                curr += '1';
            }
            else {
                break;
            }
        }

        while ((int) curr.size() < n) {
            if (ask('0' + curr)) {
                curr = '0' + curr;
            }
            else {
                curr = '1' + curr;
            }
        }
        cout<<"! "<<curr<<endl; 
        cout.flush();
    }
}