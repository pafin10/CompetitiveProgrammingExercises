#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>

#define endl "\n"
#define ll long long 
using namespace std;

int main() {
    ifstream cin("approx2.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n, k; cin>>n>>k; 
        vector<int> a(n);
        for (int i = 0; i<n; i++) {
            cin>>a[i];
        }
        // edge case n = 2
        if (n==2) {
            cout<<abs(a[0] + a[1] - k)<<" "<<1<<endl;
            continue;
        } 
        ll mini = 10E10, cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i != j) {
                    if (abs(a[i] + a[j] - k) < mini) {
                        mini = abs(a[i] + a[j] - k);
                        cnt = 1;
                    }
                    else if (abs(a[i] + a[j] - k) == mini) cnt++;
                }
            }
        }
        cout<<mini<<" "<<cnt<<endl;
    }
	return 0;
}