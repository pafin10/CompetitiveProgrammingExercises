#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    // ANALYZE TOMORROW
     ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        ll n; cin>>n; 
        vector<ll> a(n);
        it (i, n) cin>>a[i];

        vector<ll> l(n), r(n);
        int beg = 0;
        while (beg<n) {
            int end = beg; 
            while(end + 1 < n && a[end+1] == a[end]) end++;
            for (int i = beg; i <= end; i++) {
                l[i] = beg; 
                r[i] = end;
            }
            beg = end+1;
        }
        vector<ll> pref(n+1);
        it (i, n) {
            pref[i+1] = pref[i] + a[i];
        }
        const int inf = int(1e9);
        vector<int> ans(n, inf);
        it (i, n) {
            if (i > 0 && a[i-1] > a[i]) {
                ans[i] = 1;
            }
            if (i < n-1 && a[i+1] > a[i]) {
                ans[i] = 1;
            }
            { // left
                if (i > 0 && l[i-1] > 0) {
                    int low = -1, high = l[i-1] - 1;
                    while(low < high) {
                        int mid = (low+high+1) >> 1;
                        if (pref[i] - pref[mid] > a[i]) {
                            low = mid;
                        }
                        else {
                            high = mid -1; 
                        }
                    }
                    if (low >= 0) {
                        ans[i] = min(ans[i], i-low);
                    }
                }
            }
            { // right
                if (i < n-1 && r[i+1] < n-1) {
                    int low = r[i+1] + 1, high = n; 
                    while (low < high) {
                        int mid = (low + high) >> 1;
                        if (pref[mid + 1] - pref[i+1] > a[i]) {
                            high = mid; 
                        }
                        else {
                            low = mid + 1;
                        }
                    }
                    if (low < n) {
                        ans[i] = min(ans[i], low - i);
                    }
                }
            }
        }
        it (i, n) cout << (ans[i] == inf ? -1 : ans[i]) << " \n"[i == n-1];
    }
	return 0;
}