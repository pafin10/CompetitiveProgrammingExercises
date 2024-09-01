#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t; 
    while(t--) {
        int x, y; cin >> x >> y;
        
        int lsbDiff = 1;
        while ((x & 1) == (y & 1)) {
            x >>= 1;
            y >>= 1;
            lsbDiff++;
        }
        
        int period = 1 << (lsbDiff - 1);
        cout<<period<< endl; 
    }
    return 0;
}
