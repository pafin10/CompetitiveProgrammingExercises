#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define ll long long 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll c; cin>>c; 
        ll numBits = sizeof(c) * 8;
        bool first = true;
        ll a = 0, b = 0;
        
        for (int i = numBits-1; i>=0; i--) {
            int bitVal = (c>>i) & 1;
            if (bitVal == 0 && first) continue;
            int bitmask = 0;
            if (bitVal == 1 && first) {
                first = false; 
                bitmask = 1 << i;
                a |= bitmask;
            }
            else if (bitVal == 1) {
                bitmask = 1 << i;
                b |= bitmask;
            }
            else {
                bitmask = 1 << i;
                a |= bitmask;
                b |= bitmask;
            }
        }
        
        cout<<a*b<<endl;
        
    }
	return 0;
}