#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> cnts;
    for (char c : s) cnts[c]++;

    long long res = 1;
    int numPos = s.length();

    for (const auto& kv : cnts) {
        char letter = kv.first;
        int count = kv.second;
        long long factor = 1;

        for (int i = 2; i <= count; ++i) {
            factor *= i;
        }

        res *= tgamma(numPos) / factor;
        numPos -= count;
    }

    if (cnts.size() == 1) {
        cout << 1 << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}
