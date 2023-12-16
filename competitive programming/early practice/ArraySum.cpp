#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void solve();

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    ll sum = 3<+n/2;
    ll diff = k - sum;

    if (k < sum || k > n*10E5 - n/2) {
        cout << -1 << endl; return;
    }

    if (diff % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (i%2 == 0) arr[i] = 1;
        else arr[i] = 2;
    }

    ll add = diff/n;
    ll rest = diff%n; //to add all of diff to the array
    for (int i = 0; i < n; i++) arr[i]+=add;
    for (int i = 0; i < rest; i++) arr[i]++;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
