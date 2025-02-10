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
#include <deque>


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
    // ifstream cin("absoluteZero.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n;
        vector<int> a(n);

        int ans = 0;
        set<int> unq;

        for (auto& i: a) {
            cin>>i; 
            unq.insert(i);
        }
        if ((int)unq.size() == 1) {
            cout<<1<<endl; 
            cout<<a[0]<<endl; 
            continue; 
        }
        auto it = unq.begin(); 
        for (auto it1 = unq.begin(); it1 != unq.end(); it1++) {
            if (abs(*it - *it1) % 2) ans = -1;
        }
        if (ans == -1) {
            cout<<ans<<endl; 
            continue;
        }

        vector<int> moves; 
        int maxi, mini, sub; 

        for (int i = 0; i < 40; i++) {
            sort(a.rbegin(), a.rend());
            maxi = *unq.rbegin();
            if ((int)unq.size() > 1) {
                auto it = unq.begin();
                mini = *it;
                sub = mini + (maxi - mini) / 2;
            }
            else sub = maxi;              
            moves.push_back(sub);
            
            bool allZero = true;
            unq.clear();
            for (int j = 0; j < n; j++) {
                a[j] -= sub;
                a[j] = abs(a[j]);
                unq.insert(a[j]);
                if (a[j]) allZero = false; 
            }
            if (allZero) break; 
        }
        if (ans == -1) cout<<ans<<endl; 
        else {
            cout<<(int)moves.size()<<endl;
            for (auto& m: moves) cout<<m<<" ";
            cout<<endl; 
        }
    }
}