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
//#define int long long
const int MAX_N = 100'005;

int win(int x1, int y1, int x2, int y2) {
    int suneetWins = 0, slavicWins = 0;
    if (x1 > y1) suneetWins++;
    else if (x1 < y1) slavicWins++;
    
    if (x2 > y2) suneetWins++;
    else if (x2 < y2) slavicWins++;
    
    if (suneetWins > slavicWins) return 1;
    else return 0;
}

int32_t main() {
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        int winCount = 0;
        winCount += win(a1, b1, a2, b2);
        winCount += win(a2, b1, a1, b2);
        winCount += win(a1, b2, a2, b1);
        winCount += win(a2, b2, a1, b1);
        
        cout << winCount << endl;
    }
    return 0;
}
