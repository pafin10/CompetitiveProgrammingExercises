#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define ll long long
using namespace std;

int main() {
    ifstream cin("pma.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        ll altsum = 0;
        ll smallestPos = 10E10; ll sPindex = 0;
        ll largestNeg = 0; ll lNindex = 0;
        vector<ll> a(n);
        for (int i = 0; i<n; i++) {
            cin>>a[i];
            if (i%2==0) {
                altsum+=abs(a[i]);
                if (abs(a[i]) < smallestPos) {
                    smallestPos = abs(a[i]);
                    sPindex = i;
                }
            }
            else {
                altsum -= abs(a[i]);
                if (abs(a[i]) > largestNeg) {
                    largestNeg = abs(a[i]);
                    lNindex = i;
                }
            }
        }

        if (smallestPos > largestNeg) cout<<altsum<<endl;
        else {
            altsum += 2* abs(largestNeg - smallestPos);
            cout<<altsum<<endl;
        }
    }
	return 0;
}