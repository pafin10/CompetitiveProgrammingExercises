#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>
#include <deque>


using namespace std;
#define NDEBUG
#define ll long long
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;


int32_t main() {
    // ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while (t--) {
    int n, d; 
    cin>>n>>d; 
    set<int> ans = {1};  

    if (d == 5) ans.insert(5);
    if (d % 3 == 0) ans.insert(3);  
    if (d == 9) ans.insert(9);
    if (d == 7) ans.insert(7);

    if (n >= 6) {
        ans.insert(3);
        ans.insert(9);
    } 
    else {
        int factorial = 1;
        for (int i = 2; i <= n; i++) {
            factorial *= i;
        }

        if ((factorial * d) % 7 == 0) ans.insert(7);
        if ((factorial * d) % 3 == 0) ans.insert(3);
        if ((factorial * d) % 9 == 0) ans.insert(9);
    }
    int num = d;
    int until = INF;  
    if (n == 2) until = 2; 
    if (n == 3) until = 6; 

    for (int i = 1; i <= min(5, until); i++) {
        num = num * 10 + d;
    }
    if (!(num % 7)) ans.insert(7);

    for (auto i : ans) cout << i << " ";
    cout << endl;
}

}