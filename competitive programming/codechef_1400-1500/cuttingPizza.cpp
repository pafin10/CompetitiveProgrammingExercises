#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <numeric>
using namespace std;

int main() {
    ifstream cin("cuttingPizza.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        vector<int> s(n);
        bool sameDiff = true;
        vector<int> diffs;
        
        for (int i = 0; i<n; i++) cin>>s[i];
        int diff = 0, last = s[1] - s[0], minDiff = 1000;
        for (int i = 1; i<n; i++) {
            diff = s[i] - s[i-1];
            if (diff < minDiff) minDiff = diff;
            diffs.push_back(gcd(diff, last));
            if (diff != last) sameDiff = false; 
            last = diff; 
        }
        diffs.push_back(360 - s[n-1] + s[0]);
        if (sameDiff && abs(s[n-1] - 360) == diff) {cout<<0<<endl; continue; }
        else if (360%minDiff == 0) cout<<360/minDiff - n<<endl; 
        else {
            int gCom = 1200;
            for (int i = 1; i<diffs.size(); i++) {
                if (gcd(diffs[i], diffs[i-1]) < gCom) gCom = gcd(diffs[i], diffs[i-1]);
            }
            cout<<360/gCom - n<<endl;
        }
    }
	return 0;
}