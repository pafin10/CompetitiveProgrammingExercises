#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// CORRECT SOLUTION; REMEMBER THIS: ALWAYS DOUBLE CHECK LOGIC, JUST SORTING THE ARRAY DOESNT DO IT HERE

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        long long sm = 0;
        int cursed = 0; 
        vector<int> cursedElements;
        vector<int> nonCursedElements;
        
        for (int i = 0; i < n; i++) {
            if (sm>=a[i] && i != 0) {
                cursedElements.push_back(a[i]);
                cursed++;
            }
            else sm+=a[i];
        }
        
        set_difference(a.begin(), a.end(), cursedElements.begin(), cursedElements.end(), back_inserter(nonCursedElements));
        
        vector<int> ans;
        for (int i = 0; i < nonCursedElements.size(); i++) ans.push_back(nonCursedElements[i]);
        for (int j = 0; j < cursedElements.size(); j++) ans.push_back(cursedElements[j]);
        
        cout<<cursed<<"\n";
        for (int i = 0; i < n; i++) cout<<ans[i]<<" ";
        cout<<"\n";
        
    }
    cout<<flush;
	return 0;
}