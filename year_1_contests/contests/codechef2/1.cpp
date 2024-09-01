#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n;
        vector<int> perm(n);
        for (int i = 1; i <=n; i++) cin>>perm[i];
        reverse(perm.begin(), perm.end());
        for (int i = 1; i <=n; i++) cout<<perm[i]<<" ";
        cout<<endl;
    }
	return 0;
}
