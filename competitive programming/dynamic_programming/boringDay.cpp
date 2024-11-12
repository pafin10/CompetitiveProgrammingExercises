#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
#define int long long

int32_t main() {
    //ifstream cin("boringDay.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int cnt = 0;
        int sum = 0;
        int start = 0;
        
        for (int end = 0; end < n; ++end) {
            sum += a[end];
            while (sum > r) {
                sum -= a[start];
                start++;
            }
            if (sum >= l) {
                cnt++;
                sum = 0;
                start = end + 1;
            }
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}
