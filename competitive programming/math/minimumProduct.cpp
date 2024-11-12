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

    // ifstream cin("minimumProduct.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin>>t; 
    while(t--) {
        ll a, b, x, y, n; 
        cin>>a>>b>>x>>y>>n;
        ll minValA = (a - n >= x) ? a - n : a - (a-x); 
        ll minValB = (b - n >= y) ? b - n : b - (b-y);

        if (minValA < minValB) {
            n -= (a - minValA);
            a = minValA;
            b - minValB <= n ? b = minValB : b -= n;
        }
        else {
            n -= (b - minValB);
            b = minValB;
            a - minValA <= n ? a = minValA : a -= n;
        }
        cout<<a*b<<endl; 
    }
    return 0;
}
