#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n;

        vector<int> a;
        vector<int> b;
        vector<int> full(n);
        ll cumSum = 0; 
        for (int i = 0; i < n; i++) {
            cumSum += i+1; 
            full[i] = i+1;
        }
        
        if (cumSum % 2 != 0) {cout<<"NO"<<endl; continue; }
        for (int i = 0; i < n/2; i++) {
            if (i%2==0) {
                a.push_back(full[i]);
                a.push_back(full[n-1-i]);
            }
            else {
                b.push_back(full[i]);
                b.push_back(full[n-1-i]);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout<<"YES"<<endl; 
        for (auto &el: a) cout<<el<<" ";
        cout<<endl; 
        for (auto &el: b) cout<<el<<" ";
    }
	return 0;
}
