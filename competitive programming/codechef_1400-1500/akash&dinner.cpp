#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t; 
    while(t--) {
        ll n, k; cin>>n>>k; 
        vector<ll> a(n), b(n);
        set<ll> cat;
        map<ll, ll> c;
        ll dist = 0;
        
      
        for (int i = 0; i<n; i++) {
            cin>>a[i];
            cat.insert(a[i]);
        }
    
        for (int i = 0; i<n; i++) cin>>b[i];
        if (cat.size() < k) {
            cout<<-1<<endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            c[a[i]] = (c.find(a[i]) == c.end()) ? b[i] : min(b[i], c[a[i]]); 
        }
        
        // copy pairs to vector
        vector<pair<int, int>> pairs(c.begin(), c.end());
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        ll sm = 0; int cnt = 0;
        for (int i = 0; i<k; i++) {
            sm += pairs[i].second;
        }
        cout<<sm<<endl;
        cin.clear();
    }
	return 0;
}
