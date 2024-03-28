#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)
#define pb push_back


int main(int argc, char const *argv[]) {

    // ifstream cin("cardboardForPictures.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t; cin>>t; 
    while(t--) {
        ll n, c; cin>>n>>c; 
        ll maxi = 0;
        vector<ll> sizes(n);
        it(i, n) {
            cin>>sizes[i];
            if (sizes[i] > maxi) maxi = sizes[i];
        }

        ll left = 1; ll right = 10E9; 
        while (left < right) {
            ll mid = left + (right - left) / 2;
            ll res = 0;
            for (auto val : sizes) {
                res += (val + mid) * (val+mid);
                if (res > c) break;
            }
            if (res < c && res > 0) {
                left = mid+1;
            }
            else {
                right = mid; 
            }
        }
        cout<<left/2<<endl;
    }

    return 0;
}
