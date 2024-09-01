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
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; t=1;//cin>>t; 

    while(t--) {
        int n, d; cin>>n>>d; 
        vi row(n+1, 0), col(n+1, 0);
        int diagCnt1 = 0, diagCnt2 = 0;
        int ans = -1;
        bool found = false; 

        it(i,0,d) {
            int j; 
            cin>>j;
            int currRow = int(ceil((double)j/n));
            int currCol;
            if (j%n != 0) currCol = j%n; 
            else currCol = int(ceil((j-1)%n))+1;
            row[currRow]++;
            col[currCol]++;
            if (currRow == currCol) diagCnt1++;
            if (currRow+currCol == n+1) diagCnt2++;
            if (!found && (row[currRow] == n || col[currCol] == n || diagCnt1 == n || diagCnt2 == n)) {
                ans = i+1;
                found = true;
            }
        }
        cout<<ans<<endl; 
    }
}