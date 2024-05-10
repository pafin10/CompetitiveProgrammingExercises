#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>


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
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    ifstream cin("xor-distance.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll a,b,r; cin>>a>>b>>r; 
        ll ans = 0;
        bool firstBit = false;
        if (max(a,b) > r) firstBit = true; 
        ll msB = 0, k = 1;
        while ((k << 1) <= r) {k = k << 1; msB++;}
        for (ll mask = msB; mask >= 0; mask--) {
            if (firstBit) {
                if (a > b) {
                    if (((1<<mask) & a) && !((1<<mask) & b)) {
                        if ((ans | (1<<mask)) < r) ans |= (1<<mask); 
                    }
                }
                else {
                    if (((1<<mask) & b) && !((1<<mask) & a)) {
                        if ((ans | (1<<mask)) < r) ans |= (1<<mask); 
                    }
                }
            }
            if (((1<<mask) & a) ^ ((1<<mask) & b)) firstBit = true; 
        }
        ll out = abs((a ^ ans) - (b ^ans));
        cout<<out<<endl; 
    }
}