#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[]) {
    //ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 
    while (t--) {
        int n; 
        cin >> n; 

        vector<int64_t> a(n);
        int groups = n;
        it(i, n) cin >> a[i];
        // define leftmost and rightmost position in vector, so min and max el after sorting 
        int l = 0, r = n-1; 
        int64_t inf = (int64_t(1) << 31) - 1;
        sort(a.begin(), a.end());
        while (l<r) {
            // this is equivalent to saying that their XOR is 1 for all bits up to the 31st
            if (a[l] + a[r] == inf) {
                groups--;
                l++, r--;
            }
            else if (a[l] + a[r] > inf) {
                r--;
            }
            else {
                l++;
            }
        }
        cout<<groups<<endl; 
    }
    return 0;
}

