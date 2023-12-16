#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    //ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool isBigger = false;
        bool skip = false;

        for (int i = 0; i < n; ++i) {
            int nextPower = 1;

            while (nextPower <= n) {
                skip = false;
                if (i + 1 < nextPower) {
                    skip = false;
                    break;
                }
                if (i + 1 == nextPower) {
                    skip = true;
                    break;
                }
                nextPower *= 2;
            }
            if (skip) continue;
            int lim = min(nextPower, n);

            for (int j = i + 1; j < lim; j++) {
                if (a[j] < a[i]) {
                    isBigger = true;
                    break;
                }
            }
        }

        if (isBigger) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}



