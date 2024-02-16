#include <iostream>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        // Pattern 1 & 2
        ll opt_1_2 = 0;
        ll opt_3 = 0;
        ll opt_4_5 = 0;
        
        if (n==2) {
            cout<<4<<endl; 
            continue;
        }
        // All Patterns
        else if (n==3) {
            cout<<42<<endl;
            continue;
        }
        else {
            // Flag 1 & 2
            ll threeCol = 1;
            for (int i = n; i> (n-3); i--) {
                threeCol *= i;
            }
            ll twoCol = 1;
            for (int i = n; i> (n-2); i--) {
                twoCol *= i;
            }
            opt_1_2 = twoCol + threeCol;
            twoCol =1, threeCol =1;
            
            // Flag 3
            for (int i = n; i> (n-3); i--) {
                threeCol *= i;
            }
            opt_3 = threeCol;
            threeCol = 1;
            
            // Flag 4 & 5 
            for (int i = n; i> (n-4); i--) {
                threeCol *= i;
            }
            for (int i = n; i> (n-3); i--) {
                twoCol *= i;
            }
            opt_4_5 = threeCol+twoCol;
        }
        cout<<opt_1_2*2+opt_3+opt_4_5*2<<endl;
    }
	return 0;
}
