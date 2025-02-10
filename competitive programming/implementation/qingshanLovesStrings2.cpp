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
    // ifstream cin("qingshanLovesStrings2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vector<char> s(n);
        int ones = 0, zeros = 0;

        for (auto& i: s) {
            cin>>i; 
            if (i == '1') ones++;
            else zeros++;
        }

        if (n % 2 || (ones != zeros)) {
            cout<<-1<<endl; 
            continue;
        }

        deque<char> d(s.begin(), s.end()); 
        int i = 0, j = n - 1, cnt = 0;
        vi pos; 

        while (i <= j) {
            if (d[i] == d[j]) {
                cnt++;
                if (d[i] == '0') {
                    d.insert(d.begin() + j + 1, '0'); 
                    d.insert(d.begin() + j + 2, '1');
                    pos.pb(j + 1);
                }
                else {
                    d.insert(d.begin() + i, '0'); 
                    d.insert(d.begin() + i + 1, '1');
                    pos.pb(i);
                }
                i = 0; j = d.size() - 1;
                continue;
            }
            i++; j--;
        }
        
        cout<<pos.size()<<endl; 
        for (auto e: pos) {
            cout<<e<<" ";
        }
        cout<<endl; 
        
    }
}