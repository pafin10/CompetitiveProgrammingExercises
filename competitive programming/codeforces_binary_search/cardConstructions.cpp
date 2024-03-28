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
#define pb push_back

int main(int argc, char const *argv[]) {

    // ifstream cin("cardConstructions.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> pyramids; 
    pyramids.push_back(0);
    pyramids.push_back(2);
    ll height = 2; 
    while(pyramids[height-1] + (3*height-1) < 1000100000) {
        pyramids.pb(pyramids[height-1] + (3*height-1));
        height++;
    }

    int t; cin>>t; 
    while(t--) {
        ll n; cin>>n;
        ll i = 0, ans = 0;

        // Binary search to find the closest pyramid height
        ll left = 0, right = pyramids.size() - 1;
        while (n >= 2) {
            left = 0, right = pyramids.size() - 1;
            while (left < right) {
                ll mid = left + (right - left) / 2;
                if (pyramids[mid] <= n) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            n -= pyramids[left-1];

            // Increment ans only if n is still positive
            if (n >= 0) {
                ans++;
            } else {
                break;
            }
        }

        cout<<ans<<endl;
    
    }

    return 0;
}
