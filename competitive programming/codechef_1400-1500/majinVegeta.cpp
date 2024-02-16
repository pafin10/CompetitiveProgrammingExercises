#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <fstream>

#define endl "\n"
#define ll long long 
using namespace std;


vector<int> computePrimeFactors(int n) {
    vector<int> pf; 
    int z = 2;
    while(z*z <= n && n>1) {
        if (n % z == 0) {
            pf.push_back(z);
            n /= z;
        }
        else z++;
    }
    if (n>1) pf.push_back(n);
    return pf;
}

int main() {
    ifstream cin("majinVegeta.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n, m; cin>>n>>m; 
        int energy = 0;
        for (int i = n; i<m; i++) {
            vector<int> pf = computePrimeFactors(i);
            set<int> distinctPF(pf.begin(), pf.end());
            energy += distinctPF.size();
        }
        cout<<energy<<endl;
    }
	return 0;
}