#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main() {
    //ifstream cin("2.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll maxIndex = log2(1000000000) + 1;
    vector<ll> minArray(maxIndex+1);
    ll sm;
    minArray[0] = sm = 1;
    for (int i = 1; i < maxIndex+1; i++) {
        minArray[i] = sm + 1;
        sm += minArray[i];
    }
    int t; cin>>t; 
    while(t--) {
        ll n, k, x; cin>>n>>k>>x; 
        if (k > maxIndex) {
            cout<<"No"<<endl;
        }
        else {
            x >= minArray[k-1] ? cout<<"Yes"<<endl : cout<<"No"<<endl; 
        }
    }
	return 0;
}
