#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <fstream>
#include <map>
#include <cmath>

using namespace std;
#define ll long long

int main() {
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < q; ++i) {
            int x;
            cin >> x;
            long long pow2 = (1LL << (x - 1)); // Calculate 2^(x-1) using left shift
            for (int j = 0; j < n; j++) {
                if (a[j] % (1LL << x) == 0) {
                    a[j] += pow2;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}