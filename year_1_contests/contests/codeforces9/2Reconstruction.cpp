#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <cmath>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main() {
    // monsters and health cant be separated, must be considered together as we sort one
    //ifstream cin("2.txt");
    int t;
    cin >> t;
    while(t--) {
        ll n,k; cin>>n>>k; 
        vector<ll> health(n), dist(n+1, 0), runSum(n+1);
        it(i, n) cin>>health[i];
        it(i, n) {
            int j; cin>>j; 
            j = abs(j);
            dist[j] += health[i];
        }
        ll sm = 0; bool valid = true; 
        for (int i = 1; i <= n; i++) {
            sm = sm + dist[i];
            if (sm > i*k) {
                valid = false; 
                break;
            }
        }
        if (valid) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
    }
    

    return 0;
}
