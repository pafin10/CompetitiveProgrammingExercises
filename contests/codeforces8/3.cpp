#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

vector<int> precomputeDigitSums(int maxi) {
    vector<int> out(maxi+10);
    out[0] = 0;
    for (int i = 1; i < out.size(); i++) {
        out[i] = out[i-1];
        int x = i; 
        while (x > 0) {
            out[i] += (x%10);
            x /=10;
        }
    }
    return out; 
}

int main() {
    //ifstream cin("3.txt");
    int t;
    cin >> t;
    int upper = pow(10, 5) * 2;
    vector<int> digSums = precomputeDigitSums(upper);
    while (t--) {
        ll n;
        cin >> n;
        ll ans = digSums[n];
        cout << ans << endl;
    }

    return 0;
}
