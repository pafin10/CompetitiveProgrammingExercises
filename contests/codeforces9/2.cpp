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
    //ifstream cin("2.txt");
    int t;
    cin >> t;
    const int N = 3E5 + 20;
    ll cnt[N];
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> dist(n), health(n);

        it(i, n) cin >> health[i];
        it(i, n) {
            ll j; cin>>j; 
            dist[i] = abs(j);
        }
        it (i, n+1) cnt[i] = 0;
        it (i,n) cnt[dist[i]] += health[i];  

        ll sm = 0; bool valid = true;
        it(i, n+1) {
            sm += cnt[i];
            if (sm > i*k) {
                valid = false; 
                break;
            }
        }
        valid ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }

    return 0;
}
