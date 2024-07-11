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
    //ifstream cin("chefAndSquares.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int k; cin>>k; 
        vector<vi> grid(k);
        vi perm(k); 
        it(i,1,k+1) perm[i-1] = i;
        rotate(perm.begin(), perm.begin()+1, perm.end());
        grid[k/2] = perm; 
        vi midPerm = perm; 
        rotate(perm.begin(), perm.begin()+1, perm.end());
 
        it(i, k/2+1, k) {
            grid[i] = perm;
            rotate(perm.begin(), perm.begin()+1, perm.end());
        } 
        rotate(midPerm.begin(), midPerm.end()-1, midPerm.end());
        itb(i, k/2-1, 0) {
            grid[i] = midPerm; 
            rotate(midPerm.begin(), midPerm.end() -1, midPerm.end());
        }
        for (auto& row: grid) {
            for (auto& entry: row) {
                cout<<entry<<" ";
            }
            cout<<endl; 
        }
    }
}