#include <iostream>
#include <fstream>
#define endl "\n"
#define ll long long
using namespace std;

int main(int argc, char const *argv[]) {
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        ll x, n;
        cin>>x>>n;
        // EDGE CASES
        if (n == x) {
            cout<<1<<endl;
            continue;
        }
        if (x%n == 0) {
            cout<<x/n<<endl;
            continue;
        }
        // GENERAL CASES
        ll ans = 0; 
        for (ll i = 1; i*i <= x; ++i) {
            if (x % i == 0) {
                if (n * i <= x) {
                    ans = max(ans, i);
                }
                if (n * (x/i) <= x) {
                    ans = max(ans, x/i);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
