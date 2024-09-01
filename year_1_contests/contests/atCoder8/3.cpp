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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //ifstream cin("3.txt");
    int n, m, k;
    cin>>n>>m>>k;
    
    vector<vi> tests(m);
    vector<char> results(m);


    it(i,0,m) {
        int ci;
        cin >> ci;
        tests[i].resize(ci);
        it(j,0,ci) {
            cin >> tests[i][j];
        }
        cin >> results[i];
    }

    int validCombinations = 0;

    for (int bitmask = 0; bitmask < (1 << n); ++bitmask) {
        bool valid = true;

        for (int i = 0; i < m && valid; ++i) {
            int realKeysCnt = 0;

            for (int key : tests[i]) {
                if (bitmask & (1 << (key - 1))) {
                    realKeysCnt++;
                }
            }

            if (results[i] == 'o' && realKeysCnt < k) 
                valid = false;

            if (results[i] == 'x' && realKeysCnt >= k) 
                valid = false;
            
        }

        if (valid) validCombinations++;
    }

    cout<<validCombinations<<endl;

    return 0;
}

