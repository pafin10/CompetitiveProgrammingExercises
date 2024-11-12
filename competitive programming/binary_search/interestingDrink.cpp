#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int countElementsSmallerOrEqual(const vector<int>& vec, int n) {
    auto upper = upper_bound(vec.begin(), vec.end(), n);
    return distance(vec.begin(), upper);
}

int main(int argc, char const *argv[]) {

    // ifstream cin("interestingDrink.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int SIZE = 10E6 + 10;
    vector<int> shops(SIZE);
    
    int n;
    cin >> n;

    vector<int> a(n);
    int maxi = 0;
    it(i, n) {
        cin >> a[i];
        if (a[i] > maxi) 
            maxi = a[i];
    }
    sort(a.begin(), a.end());
    it (i, maxi + 1) {
        shops[i] = countElementsSmallerOrEqual(a, i);
    }
    int q; 
    cin >> q;
    while (q--) {
        int j; 
        cin >> j;
        if (j <= maxi)
            cout << shops[j] << endl;
        else 
            cout << n << endl; 
    }
    
    return 0;
}
