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

     //ifstream cin("oddSelection.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin>>t; 
    while(t--) {
        int n, x; cin>>n>>x; 
        int oddCnt = 0;
        string ans; 
        it(i,0,n) {
            int j; cin>>j; 
            if (j%2==1) oddCnt++;
        }
        if (x == 1) {
            oddCnt >= 1 ? ans = "Yes" : ans = "No";
        }
        else if (x == n) {
            oddCnt%2==1 ? ans = "Yes" : ans = "No";
        }
        else {
            if (oddCnt == 0) ans = "No";
            else if (oddCnt == n) {
                if (x%2==1) ans = "Yes";
                else ans = "No";
            }
            else ans = "Yes";
        }
        cout<<ans<<endl;
    }
    return 0;
}
