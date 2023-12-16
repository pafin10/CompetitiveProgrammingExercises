#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    // SOLUTION
    ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        ll n,k; cin>>n>>k;
        vector<int> a(n);
        ll ans = k+1;
        for (int i = 0; i < n; i++) cin>>a[i];

        ll entr = 1;
        for (int i = 0; i < n; i++) {
            entr = a[i]; 
            while (entr % k != 0) entr++;
            ans = min(ans, entr - a[i]);
        }
        // 2<=k<=5; all but 4 are prime numbers, so treat 4 separately
        if (k == 4) {
            k = 2;
            ll p = 10;
            for (int i = 0; i < n; i++) {
                entr = a[i]; 
                while (entr % k != 0) entr++;
                ans = min(ans, entr - a[i] + p);
                p = min(p, entr - a[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
