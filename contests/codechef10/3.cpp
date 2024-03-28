#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main() {
    //ifstream cin("3.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int maxVal = 1999;
    int t; cin>>t;
    while(t--) {
        ll n, l; cin>>n>>l; 
        vector<ll> ans(n);
        if (l >= maxVal) {
            it(i, n) {
                ans[i] = i+1;
            }
        }
        else {
            ans[0] = 1;
            for (int i = 1; i <n; i++) {
                ans[i] = ans[i-1] + l;
            }
        }
        it (i, n) cout<<ans[i]<<" ";
        cout<<endl; 
    }
	return 0;
}
