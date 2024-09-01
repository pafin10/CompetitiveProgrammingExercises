#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("1.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        string a; cin>>a;
        string ans;
        
        if (n==1 || n==2) {
            for (int i = 0; i < n; ++i) {
                if (a[i] == 'R') {
                    ans += 'P';
                } else if (a[i] == 'S') {
                    ans += 'R';
                } else {
                    ans += 'S';
                }
                cout<<ans[i];
            }
            cout<<"\n";
            continue;
        }
        
        // First half
        int wins = 0; bool spec = false;
        for (int i = 0; i < n / 2; i++) {
            if (i == (n/2 - 1) && wins == 0 && n%2==0) {
                ans += (a[i] == 'R') ? 'P' : (a[i] == 'S') ? 'R' : 'S';
                wins++;
                spec = true;
            }
            if (!spec) ans += 'P';
            if (a[i] == 'R' && !spec) wins++;
        }
    
        // Handle the second half of the string
        for (int i = n / 2; i < n; i++) {
            if (n-i > (n/2 + 1 - wins)) {
                ans += 'P';
                if (a[i] == 'R') {
                    wins++;
                }
            } else {
                // Choose the lexicographically smallest winning move
                ans += (a[i] == 'R') ? 'P' : (a[i] == 'S') ? 'R' : 'S';
                wins++;
            }
        }
    
        cout << ans << "\n";
    }
	return 0;
}