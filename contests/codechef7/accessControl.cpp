#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ifstream cin("exactSav.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll n,x,z; // z are savings he wants in the end
        cin>>n>>x>>z;
        vector<ll> a(n); ll sm = 0;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            sm += a[i];
        }
            
        if (z%x == 0) {cout<<z/x<<endl; continue; }
    
        vector<bool> dp(sm+1, false);
        dp[0] = true; // empty subset
        
        // For each gift price a[i], update dp[j] for all j from sm to a[i]
        for (int i=0; i<n; i++) {
            for (int j=sm; j>=a[i]; j--) {
                dp[j] = dp[j] || dp[j - a[i]];
            }
        }
        
        // Now dp[j] is true if there is a subset of gift prices with sum j
        // We can iterate over dp from z to sm and check if (i+z) is divisible by x
        bool pos = false;
        for (ll i=z; i<=sm; i++) {
            if (dp[i] && (i+z)%x == 0) {
                cout<<(i+z)/x<<endl;
                pos = true;
                break;
            }
        }
        if (!pos) cout<<-1<<endl;
    }
	return 0;
}
