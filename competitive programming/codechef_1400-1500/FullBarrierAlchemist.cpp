#include <iostream>
#include <vector> 
#include <string>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n, h, y1, y2, l; 
        cin>>n>>h>>y1>>y2>>l;
        
        vector<pair<int, int>> entr(n);
        for (int i = 0; i<n; i++) {
            cin>>entr[i].first>>entr[i].second;
        }
        
        int ans = -1; 
        for (int i = 0; i<n; i++) {
            if (entr[i].first == 1) {
                if (h-y1 > entr[i].second) l--;
            }
            else {
                if (y2 < entr[i].second) l--;
            }
            if (l==0) {
                ans = i;
                break;
            }
        }
        if (ans == -1) ans = n;
        cout<<ans<<endl;
    }
	return 0;
}