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
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back


int main(int argc, char const *argv[]) {

    // ifstream cin("queueSort.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n;
        bool poss = true;
        int ans = 0, mini = INT32_MAX;
        bool suffStart = false;
        vector<int> a(n);
        it(i,0,n) {
            cin>>a[i]; 
            if (suffStart) {
                if (a[i] < a[i-1]) {
                    poss = false; 
                    suffStart = false;
                }
            }
            if (a[i]<mini) {
                mini = a[i]; 
                suffStart = true; 
                poss = true; 
                ans = i;
            }
        }
        if (poss) cout<<ans<<endl; 
        else cout<<-1<<endl;
    }
    return 0;
}
