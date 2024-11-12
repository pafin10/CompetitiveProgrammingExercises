#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
#define ll long long

int main() {
    // ifstream cin("shovelsAndSwords.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        // Calculate the maximum number of shovels and swords that can be crafted
        ll ans = min(min(a, b), (a + b) / 3);
        
        cout << ans << endl;
    }

    return 0;
}
