#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        bool sub = true;
        int posA = -1, posB = -1, posC = -1;
        int i = 0;

        while (a != b && sub && i < n) {
            sub = false;
            for (; i < n; ++i) {
                if (b[i] == 'c' && a[i] != 'c') {
                    posC = i;
                } else if (b[i] == 'b') {
                    posB = i;
                } else if (b[i] == 'a') {
                    if (a[i] != 'a')
                        posA = i;
                    if (posC < posB && posB < posA) {
                        // handle subseq
                        if (a[posA] == 'a' && a[posB] == 'b' && a[posC] == 'c')
                            continue;
                        else {
                            b[posC] = 'a';
                            b[posA] = 'c';
                            sub = true;
                            // Resetting i to the minimum value of posA, posB, and posC
                            i = min(min(posA, posB), posC);
                            break;
                        }
                    }
                }
            }
        }

        if (a == b)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
