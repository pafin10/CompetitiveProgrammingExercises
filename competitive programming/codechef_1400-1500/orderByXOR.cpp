#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

#define endl "\n"
#define ll long long 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    
    while(t--) {
        int a,b,c; cin>>a>>b>>c; 
        int x = 0; 
        int bitSizea = sizeof(a) * 8;
        vector<pair<int, int>> pos; // contains bit positions and the bit that should be set in x
        bool setAB = false, setAC = false, setBC = false;
        // int has 32 bits
        for (int i = bitSizea-1; i>=0; i--) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            
            if (bitA != bitB && !setAB) {
                a>b ? pos.push_back(make_pair(i, 1)) : pos.push_back(make_pair(i, 0));
                setAB = true;
            }
            if (bitA != bitC && !setAC) {
                a>c ? pos.push_back(make_pair(i, 1)) : pos.push_back(make_pair(i, 0));
                setAC = true;
            }
            if (bitB != bitC && !setBC) {
                b>c ? pos.push_back(make_pair(i, 1)) : pos.push_back(make_pair(i, 0));
                setBC = true; 
            }
        }
        
        for (int j = 0; j<pos.size(); j++) {
            int posit = pos[j].first; 
            int bit = pos[j].second;
            x |= (bit << posit);
        }
        
        if ((a ^ x) < (b^x) && (b^x) < (c^x)) cout<<x<<endl;
        else cout<<-1<<endl;
  
    }
	return 0;
}