#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define it(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    // ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }

        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        int j = 1;
        vector<int> lOut;
        vector<int> rOut;
        while (j < n) {
            if (l[j] == l[j-1]) {
                lOut.push_back(l[j]);
                lOut.push_back(l[j-1]);
            }
            if (r[j] == r[j-1]) {
                rOut.push_back(r[j]);
                rOut.push_back(r[j-1]);
            }
            j++;
        }

         // Cut the longer vector to match the length of the shorter vector
        if (lOut.size() > rOut.size())
            lOut.resize(rOut.size());
        else if (rOut.size() > lOut.size())
            rOut.resize(lOut.size());

        if (rOut.size() >= 2*k) {
            it(i, 2*k) {
                cout<<lOut[i]<<" ";
            }
            cout<<endl;
            it(i, 2*k) {
                cout<<rOut[i]<<" ";
            }
            cout<<endl;  
        }
        else {
            int m = 0; j = 0;
            while(lOut.size() < 2*k) {
                if (l[m] == r[j]) {
                    lOut.push_back(l[m]);
                    rOut.push_back(r[j]);
                    m++; j++;
                }
                else if (l[m] < r[j]) m++;
                else j++;
            }
                
            it(i, 2*k) {
                cout<<lOut[i]<<" ";
            }
            cout<<endl;
            it(i, 2*k) {
                cout<<rOut[i]<<" ";
            }
            cout<<endl;    
        }
    }
    return 0;
}
