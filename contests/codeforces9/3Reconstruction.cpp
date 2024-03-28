#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main() {
    // monsters and health cant be separated, must be considered together as we sort one
    // ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n,q; cin>>n>>q; 
        vector<ll> c(n), runSum(n+1), minSum(n+1);
        it (i, n) {
            cin>>c[i];
            runSum[i+1] = runSum[i] + c[i];
            minSum[i+1] = minSum[i] + (c[i] == 1 ? 2 : 1);
        }
            
        it(i, q) {
            ll l,r; cin>>l>>r; 
            if (l==r) {cout<<"NO"<<endl; continue;}
            ll a = runSum[r] - runSum[l-1]; 
            ll b = minSum[r] - minSum[l-1];
            if (a >= b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
