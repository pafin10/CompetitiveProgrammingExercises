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
#include <array>


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
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;
const int N = 3000 + 2;


int32_t main() {
    // ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n; 
    vector<vector<char>> A(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>A[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++) {
        int first = i, last = n - 1 - i;
        for (int j = first; j < last; j++) {
            int off = j - first; 

            char top = A[first][j];
            A[first][j] = A[last - off][first];
            A[last - off][first] = A[last][last - off];
            A[last][last - off] = A[j][last];
            A[j][last] = top;
        }
    }

    for (auto row : A) {
        for (auto el : row) {
            cout<<el;
        }
        cout<<endl; 
    }
}