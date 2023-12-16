#include <string>
#include <vector>
#include <iostream>
 
#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
 
using namespace std;
 
inline int nxt() {
	int x;
	cin >> x;
	return x;
}
 
void solve() {
	int n = nxt();
	string s;
	cin >> s;
	int cnt = 0;
	int can_2 = 0;
	int can_1 = 0;
	for (int i = 0; i < n - 1 - i; ++i) {
		(s[i] == s[n - 1 - i] ? can_2 : cnt) += 1;
	}
	if (n % 2 == 1) {
		can_1 += 1;
	}
	string ans(n + 1, '0');
    for (int i = 0; i < can_1; ++i) {
        for (int j = 0; j < can_2; ++j) {
            ans[i + 2*j + cnt] = '1';
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = nxt();
    while (t--) {
        solve();
    }

    return 0;
}
	

