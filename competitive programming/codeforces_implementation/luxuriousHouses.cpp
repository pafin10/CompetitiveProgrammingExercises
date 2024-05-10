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

    //ifstream cin("luxuriousHouses.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin>>n; 
    vector<int> h(n);
    vector<int> ans(n);
    it(i, n) cin>>h[i];
    int maxi = 0;
    for (int i = n-1; i>0; i--) {
        ans[i-1] = max(maxi, h[i]);
        if (ans[i-1] > maxi) maxi = ans[i-1];
    }
    it (i, n) {
        int diff = ans[i] - h[i];
        diff >= 0 ? cout<<diff+1<<" " : cout<<0<<" "; 
    }
    cout<<endl;
    return 0;
}
