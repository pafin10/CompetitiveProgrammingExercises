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

static int TEN(int x) {return x == 0 ? 1 : TEN(x-1) * 10;}

int32_t main() {
    //ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n; 
    
    if (n == 1) {
        cout<<0<<endl;
        return 0;
    }
    n--;
    string s;
    for (int i = 1; i <= 40; i++) {
        int x = (i + 1) / 2;   
        if (n <= 9 * TEN(x-1)) {
            int y = TEN(x-1) + n - 1;
            s = to_string(y);
            s.resize(i, ' ');
            for (int j = x; j < i; j++) {
                s[j] = s[i - j - 1];
            }
            cout<<s<<endl; 
            return 0;
        }
        else {
            n -= 9 * TEN(x-1);
        }
    }
}