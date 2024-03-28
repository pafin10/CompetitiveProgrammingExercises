#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)


int main(int argc, char const *argv[]) {

    // ifstream cin("gettingPoints.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin>>tc; 
    while(tc--) {
        ll n, P, l, t; 
        cin>>n>>P>>l>>t; 
        ll nCopy = n; 
        ll weeks = ceil((double)n/7);
        ll cnt = weeks/2;
        ll remainingPoints = P - cnt * (2*t + l); 
        bool onlyTwoT = false; 

        if (remainingPoints == 0) {
            cout<<n-cnt<<endl; 
        }
        else if (remainingPoints < 0) {
            ll left = 1;
            ll right = cnt; 
            while (left < right) {
                ll mid = left + (right - left) / 2;
                if (P - mid * (2*t+ l) < 0) 
                    right = mid;
                else 
                    left = mid +1;
            }
            cout << n - left <<endl; 
        }
    
        else {
            while ((n-1) % 7 != 0) n--;
            if (n%2 == 1) {
                cnt++;
                remainingPoints -= (l+t);
            }
            if (remainingPoints > 0) 
                cnt += ceil((double)remainingPoints/l);
            cout<< nCopy - cnt <<endl; 
        }
    }
    
    return 0;
}
