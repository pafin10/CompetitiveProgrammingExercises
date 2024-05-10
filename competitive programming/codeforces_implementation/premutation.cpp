#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)
#define pb push_back


int main(int argc, char const *argv[]) {

    ifstream cin("premutation.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin>>t; 
    while(t--) {
        vector<int> perm;
        bool done = false; 
        int n; cin>>n; 
        it (i, n) {
            // always reset here, debug
            vector<int> line;
            it (j, n-1) {
                int k; cin>>k;
                if (i > 0) {
                    line.push_back(k);
                    if (j < n-1 && find(perm.begin(), perm.end(), k) == perm.end()) {
                        auto it = find(line.begin(), line.end(), line[j-1]);
                        if (it != line.end()) {
                            line.insert(it + 1, k);
                        }
                    }
                    else if (find(perm.begin(), perm.end(), k) == perm.end())
                        perm.push_back(k);
                }
                else perm.push_back(k);
            }
        }
        for (auto el: perm) cout<<el<<" ";
        cout<<endl;
    }
    return 0;
}
