#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n,x; cin>>n>>x; 
        vector<int> a(n); 
        bool add = false;
        if (n%2==1) add = true;
        
        for (int i = 0; i < n/2; i++) {
            a[i] = x+i+1;
        }
        for (int i = n/2; i < n; i++) {
            if (add) a[i] = x-(n-i)+1;
            else a[i] = x-(n-i);
        }
        
        if (add) a[n-1] = x;
        
        for (int i = 0; i <n; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
	return 0;
}
