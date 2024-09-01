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
#include <cctype>


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
    //ifstream cin("rudolfAndTheBallGame.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m, x; 
        cin>>n>>m>>x;
        set<int> currPos; 
        currPos.insert(x);

        for (int i = 0; i < m; i++) {
            int l; char d; cin>>l>>d; 
            set<int> pos; 
            for (auto& el : currPos) {
                if (isdigit(d)) {
                    int dir = d - '0';
                    if (dir == 0) {
                        int tmp = (el + l) % n;
                        if (tmp == 0) tmp = n; 
                        pos.insert(tmp); 
                    }
                    else {
                        int tmp = (el - l) % n;
                        if (tmp <= 0) tmp += n; 
                        pos.insert(tmp);
                    }
                }
                else {
                    int tmp = (el + l) % n;
                    if (tmp == 0) tmp = n; 
                    pos.insert(tmp); 
                    int tmp1 = (el - l) % n;
                    if (tmp1 <= 0) tmp1 += n; 
                    pos.insert(tmp1);
                }
            }
            currPos = pos; 
        }
        cout<<sz(currPos)<<endl; 
        for (auto& k : currPos) cout<<k<<" ";
        cout<<endl; 
    }
}