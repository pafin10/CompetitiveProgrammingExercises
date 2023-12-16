#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        // n is odd and should be a product of the result of x | y * x^y
        // x | y is the bitwise OR operator
        // x^y is the bitwise XOR operator
        vector<pair<int, int>> v;
        for (int i = 1; i < n/2; i += 2) {
            if (n % i == 0) {
                v.push_back(make_pair(i, n / i));
            }
        }
        v.push_back(make_pair(n, 1));
        bool found = false;
        for (const auto& pair : v) {
            for (int i = 0; i < 2; ++i) {
                int sum = i == 0 ? pair.first : pair.second;
                int xor_val = i == 0 ? pair.second : pair.first;
                // Check if at least one of the pair entries is odd
                if (sum % 2 != 0 || xor_val % 2 != 0) {
                    if ((sum % 2 == 0 && xor_val % 2 == 0) || (sum % 2 != 0 && xor_val % 2 != 0)) {
                        int x = (sum + xor_val) / 2;
                        int y = sum - x;
                        if ((x | y) == sum && (x ^ y) == xor_val) {
                            cout << x << " " << y << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
    if (found) break;
}


	return 0;
}
